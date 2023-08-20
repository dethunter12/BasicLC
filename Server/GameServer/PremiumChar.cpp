#include <boost/format.hpp>
#include "stdhdrs.h"

#ifdef PREMIUM_CHAR

#include "../ShareLib/DBCmd.h"
#include "../ShareLib/packetType/ptype_appear.h"
#include "../ShareLib/packetType/ptype_premium_char.h"
#include "Descriptor.h"
#include "Character.h"
#include "DBManager.h"
#include "Server.h"
#include "PremiumChar.h"

int PremiumChar::resetJumpCountTime = 0;

PremiumChar::PremiumChar(CPC* owner)
	: isActive_(false)
	, owner_(owner)
	, premiumType_(PREMIUM_CHAR_TYPE_FIRST)
	, expireTime_(0)
	, jumpCount_(0)
	, jumpTime_(0)
{

}

PremiumChar::~PremiumChar()
{

}

void PremiumChar::load( MYSQL* mysql_conn )
{
	CDBCmd dbChar;
	dbChar.Init(mysql_conn);

	std::string query = boost::str(boost::format(
		"SELECT  a_premiumType, a_expireTime, a_jumpCount, a_jumpTime "
		"FROM t_premiumchar WHERE a_charIndex = %1% LIMIT 1") % owner_->m_index);
	dbChar.SetQuery(query);
	if (dbChar.Open() == false)
	{
		this->reset();
		return;
	}

	if (dbChar.m_nrecords <= 0)
	{
		// �����Ͱ� ���� ���
		query = boost::str(boost::format(
			"INSERT INTO t_premiumchar(a_charIndex, a_premiumType, a_expireTime, a_jumpCount, a_jumpTime)"
			"VALUES(%1%, 0, 0, 0, 0)") % owner_->m_index);
		dbChar.SetQuery(query);
		dbChar.Update();

		this->reset();
		return;
	}

	// ������ �б�
	dbChar.MoveNext();
	dbChar.GetRec("a_premiumType", this->premiumType_);
	dbChar.GetRec("a_expireTime", this->expireTime_);
	dbChar.GetRec("a_jumpCount", this->jumpCount_);
	dbChar.GetRec("a_jumpTime", this->jumpTime_);

	if (this->expireTime_ == 0)
	{
		// �������� ������� ���� ���
		this->reset();
	}
	else
	{
		this->isActive_ = true;

		// �߿� : �ε��� expire �˻�� Server::CharPrePlay()���� ������ ������ �� �ٷ� �˻�
	}
}

void PremiumChar::setExpireTime( int t )
{
	expireTime_ = t;
}

void PremiumChar::setJumpCount( int c )
{
	jumpCount_ = c;

	if (jumpCount_ == 0)
	{
		jumpTime_ = 0;
	}
	else
	{
		jumpTime_ = gserver->getNowSecond();
	}

	CNetMsg::SP rmsg(new CNetMsg);
	UpdateClient::makePremiumCharJumpCount(rmsg, jumpCount_);
	SEND_Q(rmsg, owner_->m_desc);
}

void PremiumChar::sendInfo()
{
	CNetMsg::SP rmsg(new CNetMsg);
	UpdateClient::makePremiumCharInfo(rmsg, premiumType_, expireTime_, jumpCount_);
	SEND_Q(rmsg, owner_->m_desc);
}

void PremiumChar::sendEnd()
{
	CNetMsg::SP rmsg(new CNetMsg);
	UpdateClient::makePremiumCharEnd(rmsg);
	SEND_Q(rmsg, owner_->m_desc);

	owner_->SendStatus();
}

// �� �ʸ��� üũ�ϴ� �κ�
void PremiumChar::checkExpireTime( int chk_t )
{
	if (expireTime_ == 0)
		return;

	if (expireTime_ >= chk_t)
		return;

	// �α׸� ����� �۾��̹Ƿ�, �޸� �����͸� �ʱ�ȭ(reset()) �ϱ� ������ ȣ���Ұ�
	this->saveResetLog();

	// �ð� ����
	this->reset();
	this->sendEnd();
	this->saveNow();
}

void PremiumChar::reset()
{
	isActive_ = false;

	premiumType_ = PREMIUM_CHAR_TYPE_NONE;
	expireTime_ = 0;
	jumpCount_ = 0;
	jumpTime_ = 0;

	// ������ �ٸ� ĳ���Ϳ��� ����
	CNetMsg::SP rmsg(new CNetMsg);
	UpdateClient::makeChangePremiumCharFlag(rmsg, owner_->m_index, this->isActive_);
	owner_->m_pZone->m_area->SendToAllClient(rmsg);
}

void PremiumChar::save( std::vector<std::string>& vec )
{
	std::string query;
	this->getSaveQuery(query);

	vec.push_back(query);
}

void PremiumChar::getSaveQuery( std::string& query )
{
	query = boost::str(boost::format(
		"UPDATE t_premiumchar SET "
		"a_premiumType = %1%,"
		"a_expireTime = %2%,"
		"a_jumpCount = %3%,"
		"a_jumpTime = %4% WHERE a_charIndex = %5%")
		% this->premiumType_
		% this->expireTime_
		% this->jumpCount_
		% this->jumpTime_
		% owner_->m_index);
}

void PremiumChar::saveNow()
{
	std::string query;
	this->getSaveQuery(query);

	DBManager::instance()->pushQuery(owner_->m_desc->m_index, query);
}

void PremiumChar::saveSetLog()
{
	// DB�� �α� �����
	std::string query = boost::str(boost::format(
		"INSERT INTO t_premiumchar_log VALUES(%1%, %2%, %3%, %4%, %5%)")
		% owner_->m_index
		% this->getPremiumType()
		% gserver->getNowSecond()
		% this->getExpireTime()
		% 0);
	DBManager::instance()->pushQuery(owner_->m_desc->m_index, query);

	LOG_INFO("PREMIUM_CHAR_SET - charIndex : %d : type : %d : start : %d : end : %d",
		owner_->m_index,
		this->getPremiumType(),
		gserver->getNowSecond(),
		this->getExpireTime());

}

void PremiumChar::saveResetLog()
{
	// DB�� �α� �����
	std::string query = boost::str(boost::format(
		"INSERT INTO t_premiumchar_log VALUES(%1%, %2%, %3%, %4%, %5%)")
		% owner_->m_index
		% this->getPremiumType()
		% 0
		% this->getExpireTime()
		% gserver->getNowSecond());
	DBManager::instance()->pushQuery(owner_->m_desc->m_index, query);

	LOG_INFO("PREMIUM_CHAR_RESET - charIndex : %d : type : %d : end : %d : resettime : %d",
		owner_->m_index,
		this->getPremiumType(),
		this->getExpireTime(),
		gserver->getNowSecond());
}

void PremiumChar::checkJumpCount()
{
	if (this->jumpTime_ <= this->resetJumpCountTime)
		this->setJumpCount(0);
}

void PremiumChar::setActive()
{
	isActive_ = true;

	// ������ �ٸ� ĳ���Ϳ��� ����
	CNetMsg::SP rmsg(new CNetMsg);
	UpdateClient::makeChangePremiumCharFlag(rmsg, owner_->m_index, this->isActive_);
	owner_->m_pZone->m_area->SendToAllClient(rmsg);
}

#endif
