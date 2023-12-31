include ../makefile.inc

# LANG
# LC_KOR 0
# LC_TWN 1
# LC_CHN 3
# LC_TLD 4
# LC_JPN 6
# LC_JPN_EP 6
# LC_MAL 7
# LC_USA 9
# LC_BRZ 10
# LC_HBK 11
# LC_GER 13
# LC_SPN 14
# LC_FRC 15
# LC_PLD 16
# LC_RUS 17
# LC_TUR 18
# LC_ITA 19
# LC_MEX 20
# LC_ESP_USA 21
# LC_FRA_USA 22
# LC_NLD 23
# LC_UK 24

TARGET=Helper

TARGET_DEBUG=$(TARGET)_d
TARGET_TEST=$(TARGET)_t
TARGET_TESTDEBUG=$(TARGET)_td
TARGET_QA=$(TARGET)_q
TARGET_QADEBUG=$(TARGET)_qd

LC_SRCS=$(wildcard *.cpp)
LC_OBJS=$(patsubst %.cpp,%.o,$(LC_SRCS))


all: kor


kor:
	OPT_LANG=-DLC_KOR=0 $(MAKE) $(TARGET)

kordebug:
	OPT_LANG=-DLC_KOR=0 OPT_DEBUG=-g $(MAKE) $(TARGET_DEBUG)

kortest:
	OPT_LANG=-DLC_KOR=0 OPT_TEST=-DTEST_SERVER $(MAKE) $(TARGET_TEST)

korqa:
	OPT_LANG=-DLC_KOR=0 OPT_TEST=-DQA_SERVER $(MAKE) $(TARGET_QA)

kortestdebug:
	OPT_LANG=-DLC_KOR=0 OPT_DEBUG=-g OPT_TEST=-DTEST_SERVER $(MAKE) $(TARGET_TESTDEBUG)

korqadebug:
	OPT_LANG=-DLC_KOR=0 OPT_DEBUG=-g OPT_TEST=-DQA_SERVER $(MAKE) $(TARGET_QADEBUG)

kordep:
	OPT_LANG=-DLC_KOR=0 $(MAKE) lcdep


twn:
	OPT_LANG=-DLC_TWN=1 $(MAKE) $(TARGET)

twndebug:
	OPT_LANG=-DLC_TWN=1 OPT_DEBUG=-g $(MAKE) $(TARGET_DEBUG)

twntest:
	OPT_LANG=-DLC_TWN=1 OPT_TEST=-DTEST_SERVER $(MAKE) $(TARGET_TEST)

twntestdebug:
	OPT_LANG=-DLC_TWN=1 OPT_DEBUG=-g OPT_TEST=-DTEST_SERVER $(MAKE) $(TARGET_TESTDEBUG)

twndep:
	OPT_LANG=-DLC_TWN=1 $(MAKE) lcdep


jpn:
	OPT_LANG=-DLC_JPN=6 $(MAKE) $(TARGET)

jpndebug:
	OPT_LANG=-DLC_JPN=6 OPT_DEBUG=-g $(MAKE) $(TARGET_DEBUG)

jpntest:
	OPT_LANG=-DLC_JPN=6 OPT_TEST=-DTEST_SERVER $(MAKE) $(TARGET_TEST)

jpntestdebug:
	OPT_LANG=-DLC_JPN=6 OPT_DEBUG=-g OPT_TEST=-DTEST_SERVER $(MAKE) $(TARGET_TESTDEBUG)

jpndep:
	OPT_LANG=-DLC_JPN=6 $(MAKE) lcdep


jpnep:
	OPT_LANG=-DLC_JPN_EP=6 $(MAKE) $(TARGET)

jpnepdebug:
	OPT_LANG=-DLC_JPN_EP=6 OPT_DEBUG=-g $(MAKE) $(TARGET_DEBUG)

jpneptest:
	OPT_LANG=-DLC_JPN_EP=6 OPT_TEST=-DTEST_SERVER $(MAKE) $(TARGET_TEST)

jpneptestdebug:
	OPT_LANG=-DLC_JPN_EP=6 OPT_DEBUG=-g OPT_TEST=-DTEST_SERVER $(MAKE) $(TARGET_TESTDEBUG)

jpnepdep:
	OPT_LANG=-DLC_JPN_EP=6 $(MAKE) lcdep



tld:
	OPT_LANG=-DLC_TLD=4 $(MAKE) $(TARGET)

tlddebug:
	OPT_LANG=-DLC_TLD=4 OPT_DEBUG=-g $(MAKE) $(TARGET_DEBUG)

tldtest:
	OPT_LANG=-DLC_TLD=4 OPT_TEST=-DTEST_SERVER $(MAKE) $(TARGET_TEST)

tldqa:
	OPT_LANG=-DLC_TLD=4 OPT_TEST=-DQA_SERVER $(MAKE) $(TARGET_QA)

tldtestdebug:
	OPT_LANG=-DLC_TLD=4 OPT_DEBUG=-g OPT_TEST=-DTEST_SERVER $(MAKE) $(TARGET_TESTDEBUG)

tldqadebug:
	OPT_LANG=-DLC_TLD=4 OPT_DEBUG=-g OPT_TEST=-DQA_SERVER $(MAKE) $(TARGET_QADEBUG)

tlddep:
	OPT_LANG=-DLC_TLD=4 $(MAKE) lcdep


mal:
	OPT_LANG=-DLC_MAL=7 $(MAKE) $(TARGET)

maldebug:
	OPT_LANG=-DLC_MAL=7 OPT_DEBUG=-g $(MAKE) $(TARGET_DEBUG)

maltest:
	OPT_LANG=-DLC_MAL=7 OPT_TEST=-DTEST_SERVER $(MAKE) $(TARGET_TEST)

maltestdebug:
	OPT_LANG=-DLC_MAL=7 OPT_DEBUG=-g OPT_TEST=-DTEST_SERVER $(MAKE) $(TARGET_TESTDEBUG)

maldep:
	OPT_LANG=-DLC_MAL=7 $(MAKE) lcdep


usa:
	OPT_LANG=-DLC_USA=9 $(MAKE) $(TARGET)

usadebug:
	OPT_LANG=-DLC_USA=9 OPT_DEBUG=-g $(MAKE) $(TARGET_DEBUG)

usatest:
	OPT_LANG=-DLC_USA=9 OPT_TEST=-DTEST_SERVER $(MAKE) $(TARGET_TEST)

usaqa:
	OPT_LANG=-DLC_USA=9 OPT_TEST=-DQA_SERVER $(MAKE) $(TARGET_QA)

usatestdebug:
	OPT_LANG=-DLC_USA=9 OPT_DEBUG=-g OPT_TEST=-DTEST_SERVER $(MAKE) $(TARGET_TESTDEBUG)

usaqadebug:
	OPT_LANG=-DLC_USA=9 OPT_DEBUG=-g OPT_TEST=-DQA_SERVER $(MAKE) $(TARGET_QADEBUG)

usadep:
	OPT_LANG=-DLC_USA=9 $(MAKE) lcdep


brz:
	OPT_LANG=-DLC_BRZ=10 $(MAKE) $(TARGET)

brzdebug:
	OPT_LANG=-DLC_BRZ=10 OPT_DEBUG=-g $(MAKE) $(TARGET_DEBUG)

brztest:
	OPT_LANG=-DLC_BRZ=10 OPT_TEST=-DTEST_SERVER $(MAKE) $(TARGET_TEST)

brztestdebug:
	OPT_LANG=-DLC_BRZ=10 OPT_DEBUG=-g OPT_TEST=-DTEST_SERVER $(MAKE) $(TARGET_TESTDEBUG)

brzdep:
	OPT_LANG=-DLC_BRZ=10 $(MAKE) lcdep


hbk:
	OPT_LANG=-DLC_HBK=11 $(MAKE) $(TARGET)

hbkdebug:
	OPT_LANG=-DLC_HBK=11 OPT_DEBUG=-g $(MAKE) $(TARGET_DEBUG)

hbktest:
	OPT_LANG=-DLC_HBK=11 OPT_TEST=-DTEST_SERVER $(MAKE) $(TARGET_TEST)

hbkqa:
	OPT_LANG=-DLC_HBK=11 OPT_TEST=-DQA_SERVER $(MAKE) $(TARGET_QA)

hbktestdebug:
	OPT_LANG=-DLC_HBK=11 OPT_DEBUG=-g OPT_TEST=-DTEST_SERVER $(MAKE) $(TARGET_TESTDEBUG)

hbkqadebug:
	OPT_LANG=-DLC_HBK=11 OPT_DEBUG=-g OPT_TEST=-DQA_SERVER $(MAKE) $(TARGET_QADEBUG)

hbkdep:
	OPT_LANG=-DLC_HBK=11 $(MAKE) lcdep



ger:
	OPT_LANG=-DLC_GER=13 $(MAKE) $(TARGET)

gerdebug:
	OPT_LANG=-DLC_GER=13 OPT_DEBUG=-g $(MAKE) $(TARGET_DEBUG)

gertest:
	OPT_LANG=-DLC_GER=13 OPT_TEST=-DTEST_SERVER $(MAKE) $(TARGET_TEST)

gertestdebug:
	OPT_LANG=-DLC_GER=13 OPT_DEBUG=-g OPT_TEST=-DTEST_SERVER $(MAKE) $(TARGET_TESTDEBUG)

gerdep:
	OPT_LANG=-DLC_GER=13 $(MAKE) lcdep



gerqa:
	OPT_LANG=-DLC_GER=13 OPT_TEST=-DQA_SERVER $(MAKE) $(TARGET)

gerdebugqa:
	OPT_LANG=-DLC_GER=13 OPT_TEST=-DQA_SERVER OPT_DEBUG=-g $(MAKE) $(TARGET_DEBUG)

gerdepqa:
	OPT_LANG=-DLC_GER=13 OPT_TEST=-DQA_SERVER $(MAKE) lcdep



spn:
	OPT_LANG=-DLC_SPN=14 $(MAKE) $(TARGET)

spndebug:
	OPT_LANG=-DLC_SPN=14 OPT_DEBUG=-g $(MAKE) $(TARGET_DEBUG)

spntest:
	OPT_LANG=-DLC_SPN=14 OPT_TEST=-DTEST_SERVER $(MAKE) $(TARGET_TEST)

spntestdebug:
	OPT_LANG=-DLC_SPN=14 OPT_DEBUG=-g OPT_TEST=-DTEST_SERVER $(MAKE) $(TARGET_TESTDEBUG)

spndep:
	OPT_LANG=-DLC_SPN=14 $(MAKE) lcdep




spnqa:
	OPT_LANG=-DLC_SPN=14 OPT_TEST=-DQA_SERVER $(MAKE) $(TARGET)

spndebugqa:
	OPT_LANG=-DLC_SPN=14 OPT_TEST=-DQA_SERVER OPT_DEBUG=-g $(MAKE) $(TARGET_DEBUG)

spndepqa:
	OPT_LANG=-DLC_SPN=14 OPT_TEST=-DQA_SERVER $(MAKE) lcdep


frc:
	OPT_LANG=-DLC_FRC=15 $(MAKE) $(TARGET)

frcdebug:
	OPT_LANG=-DLC_FRC=15 OPT_DEBUG=-g $(MAKE) $(TARGET_DEBUG)

frctest:
	OPT_LANG=-DLC_FRC=15 OPT_TEST=-DTEST_SERVER $(MAKE) $(TARGET_TEST)

frctestdebug:
	OPT_LANG=-DLC_FRC=15 OPT_DEBUG=-g OPT_TEST=-DTEST_SERVER $(MAKE) $(TARGET_TESTDEBUG)

frcdep:
	OPT_LANG=-DLC_FRC=15 $(MAKE) lcdep




frcqa:
	OPT_LANG=-DLC_FRC=15 OPT_TEST=-DQA_SERVER $(MAKE) $(TARGET)

frcdebugqa:
	OPT_LANG=-DLC_FRC=15 OPT_TEST=-DQA_SERVER OPT_DEBUG=-g $(MAKE) $(TARGET_DEBUG)

frcdepqa:
	OPT_LANG=-DLC_FRC=15 OPT_TEST=-DQA_SERVER $(MAKE) lcdep


pld:
	OPT_LANG=-DLC_PLD=16 $(MAKE) $(TARGET)

plddebug:
	OPT_LANG=-DLC_PLD=16 OPT_DEBUG=-g $(MAKE) $(TARGET_DEBUG)

pldtest:
	OPT_LANG=-DLC_PLD=16 OPT_TEST=-DTEST_SERVER $(MAKE) $(TARGET_TEST)

pldtestdebug:
	OPT_LANG=-DLC_PLD=16 OPT_DEBUG=-g OPT_TEST=-DTEST_SERVER $(MAKE) $(TARGET_TESTDEBUG)

plddep:
	OPT_LANG=-DLC_PLD=16 $(MAKE) lcdep




pldqa:
	OPT_LANG=-DLC_PLD=16 OPT_TEST=-DQA_SERVER $(MAKE) $(TARGET)

plddebugqa:
	OPT_LANG=-DLC_PLD=16 OPT_TEST=-DQA_SERVER OPT_DEBUG=-g $(MAKE) $(TARGET_DEBUG)

plddepqa:
	OPT_LANG=-DLC_PLD=16 OPT_TEST=-DQA_SERVER $(MAKE) lcdep




rus:
	OPT_LANG=-DLC_RUS=17 $(MAKE) $(TARGET)

rusdebug:
	OPT_LANG=-DLC_RUS=17 OPT_DEBUG=-g $(MAKE) $(TARGET_DEBUG)

rustest:
	OPT_LANG=-DLC_RUS=17 OPT_TEST=-DTEST_SERVER $(MAKE) $(TARGET_TEST)

rusqa:
	OPT_LANG=-DLC_RUS=17 OPT_TEST=-DQA_SERVER $(MAKE) $(TARGET_QA)

rustestdebug:
	OPT_LANG=-DLC_RUS=17 OPT_DEBUG=-g OPT_TEST=-DTEST_SERVER $(MAKE) $(TARGET_TESTDEBUG)

rusqadebug:
	OPT_LANG=-DLC_RUS=17 OPT_DEBUG=-g OPT_TEST=-DQA_SERVER $(MAKE) $(TARGET_QADEBUG)

rusdep:
	OPT_LANG=-DLC_RUS=17 $(MAKE) lcdep


tur:
	OPT_LANG=-DLC_TUR=18 $(MAKE) $(TARGET)

turdebug:
	OPT_LANG=-DLC_TUR=18 OPT_DEBUG=-g $(MAKE) $(TARGET_DEBUG)

turtest:
	OPT_LANG=-DLC_TUR=18 OPT_TEST=-DTEST_SERVER $(MAKE) $(TARGET_TEST)

turtestdebug:
	OPT_LANG=-DLC_TUR=18 OPT_DEBUG=-g OPT_TEST=-DTEST_SERVER $(MAKE) $(TARGET_TESTDEBUG)

turdep:
	OPT_LANG=-DLC_TUR=18 $(MAKE) lcdep


ita:
	OPT_LANG=-DLC_ITA=19 $(MAKE) $(TARGET)

itadebug:
	OPT_LANG=-DLC_ITA=19 OPT_DEBUG=-g $(MAKE) $(TARGET_DEBUG)

itatest:
	OPT_LANG=-DLC_ITA=19 OPT_TEST=-DTEST_SERVER $(MAKE) $(TARGET_TEST)

itatestdebug:
	OPT_LANG=-DLC_ITA=19 OPT_DEBUG=-g OPT_TEST=-DTEST_SERVER $(MAKE) $(TARGET_TESTDEBUG)

itadep:
	OPT_LANG=-DLC_ITA=19 $(MAKE) lcdep


mex:
	OPT_LANG=-DLC_MEX=20 $(MAKE) $(TARGET)

mexdebug:
	OPT_LANG=-DLC_MEX=20 OPT_DEBUG=-g $(MAKE) $(TARGET_DEBUG)

mextest:
	OPT_LANG=-DLC_MEX=20 OPT_TEST=-DTEST_SERVER $(MAKE) $(TARGET_TEST)

mextestdebug:
	OPT_LANG=-DLC_MEX=20 OPT_DEBUG=-g OPT_TEST=-DTEST_SERVER $(MAKE) $(TARGET_TESTDEBUG)

mexdep:
	OPT_LANG=-DLC_MEX=20 $(MAKE) lcdep



espusa:
	OPT_LANG=-DLC_ESP_USA=21 $(MAKE) $(TARGET)

espusadebug:
	OPT_LANG=-DLC_ESP_USA=21 OPT_DEBUG=-g $(MAKE) $(TARGET_DEBUG)

espusatest:
	OPT_LANG=-DLC_ESP_USA=21 OPT_TEST=-DTEST_SERVER $(MAKE) $(TARGET_TEST)

espusatestdebug:
	OPT_LANG=-DLC_ESP_USA=21 OPT_DEBUG=-g OPT_TEST=-DTEST_SERVER $(MAKE) $(TARGET_TESTDEBUG)

espusadep:
	OPT_LANG=-DLC_ESP_USA=21 $(MAKE) lcdep


frausa:
	OPT_LANG=-DLC_FRA_USA=22 $(MAKE) $(TARGET)

frausadebug:
	OPT_LANG=-DLC_FRA_USA=22 OPT_DEBUG=-g $(MAKE) $(TARGET_DEBUG)

frausatest:
	OPT_LANG=-DLC_FRA_USA=22 OPT_TEST=-DTEST_SERVER $(MAKE) $(TARGET_TEST)

frausatestdebug:
	OPT_LANG=-DLC_FRA_USA=22 OPT_DEBUG=-g OPT_TEST=-DTEST_SERVER $(MAKE) $(TARGET_TESTDEBUG)

frausadep:
	OPT_LANG=-DLC_FRA_USA=22 $(MAKE) lcdep



nld:
	OPT_LANG=-DLC_NLD=23 $(MAKE) $(TARGET)

nlddebug:
	OPT_LANG=-DLC_NLD=23 OPT_DEBUG=-g $(MAKE) $(TARGET_DEBUG)

nldtest:
	OPT_LANG=-DLC_NLD=23 OPT_TEST=-DTEST_SERVER $(MAKE) $(TARGET_TEST)

nldtestdebug:
	OPT_LANG=-DLC_NLD=23 OPT_DEBUG=-g OPT_TEST=-DTEST_SERVER $(MAKE) $(TARGET_TESTDEBUG)

nlddep:
	OPT_LANG=-DLC_NLD=23 $(MAKE) lcdep




brzep:
	OPT_LANG=-DLC_BRZ_EP=10 $(MAKE) $(TARGET)

brzepdebug:
	OPT_LANG=-DLC_BRZ_EP=10 OPT_DEBUG=-g $(MAKE) $(TARGET_DEBUG)

brzeptest:
	OPT_LANG=-DLC_BRZ_EP=10 OPT_TEST=-DTEST_SERVER $(MAKE) $(TARGET_TEST)

brzeptestdebug:
	OPT_LANG=-DLC_BRZ_EP=10 OPT_DEBUG=-g OPT_TEST=-DTEST_SERVER $(MAKE) $(TARGET_TESTDEBUG)

brzepdep:
	OPT_LANG=-DLC_BRZ_EP=10 $(MAKE) lcdep





mexep:
	OPT_LANG=-DLC_MEX_EP=20 $(MAKE) $(TARGET)

mexepdebug:
	OPT_LANG=-DLC_MEX_EP=20 OPT_DEBUG=-g $(MAKE) $(TARGET_DEBUG)

mexeptest:
	OPT_LANG=-DLC_MEX_EP=20 OPT_TEST=-DTEST_SERVER $(MAKE) $(TARGET_TEST)

mexeptestdebug:
	OPT_LANG=-DLC_MEX_EP=20 OPT_DEBUG=-g OPT_TEST=-DTEST_SERVER $(MAKE) $(TARGET_TESTDEBUG)

mexepdep:
	OPT_LANG=-DLC_MEX_EP=20 $(MAKE) lcdep


world:
	OPT_LANG=-DLC_USA=9 OPT_DEF=-DWORLD_TOURNAMENT=100 $(MAKE) $(TARGET)

worlddebug:
	OPT_LANG=-DLC_USA=9 OPT_DEF=-DWORLD_TOURNAMENT=100 OPT_DEBUG=-g $(MAKE) $(TARGET_DEBUG)

worldtest:
	OPT_LANG=-DLC_USA=9 OPT_DEF=-DWORLD_TOURNAMENT=100 OPT_TEST=-DTEST_SERVER $(MAKE) $(TARGET_TEST)

worldtestdebug:
	OPT_LANG=-DLC_USA=9 OPT_DEF=-DWORLD_TOURNAMENT=100 OPT_DEBUG=-g OPT_TEST=-DTEST_SERVER $(MAKE) $(TARGET_TESTDEBUG)

worlddep:
	OPT_LANG=-DLC_USA=9 OPT_DEF=-DWORLD_TOURNAMENT=100 $(MAKE) lcdep

uk:
	OPT_LANG=-DLC_UK=24 $(MAKE) $(TARGET)
	
$(TARGET): $(LC_OBJS)
	$(CXX)  -o $@ $(LC_OBJS) $(OPT_LDOBJ)

$(TARGET_DEBUG): $(LC_OBJS)
	$(CXX)  -o $@ $(LC_OBJS) $(OPT_LDOBJ)

$(TARGET_TEST): $(LC_OBJS)
	$(CXX)  -o $@ $(LC_OBJS) $(OPT_LDOBJ)

$(TARGET_TESTDEBUG): $(LC_OBJS)
	$(CXX)  -o $@ $(LC_OBJS) $(OPT_LDOBJ)

$(TARGET_QA):$(LC_OBJS)
	$(CXX)  -o $@ $(LC_OBJS) $(OPT_LDOBJ)

$(TARGET_QADEBUG): $(LC_OBJS)
	$(CXX)  -o $@ $(LC_OBJS) $(OPT_LDOBJ)

.cpp .o:
	$(CXX) -c $(CFLAGS) $(CXXFLAGS) -o $@ $(patsubst %.o,%.cpp,$@)

lcdep: $(LC_SRCS)
	$(CXX) $(CXXFLAGS) $(OPT_LANG) -M $(LC_SRCS) > .depend

clean:
	rm -rf $(LC_OBJS)


cleanall:
	find . -name "*.o" -exec rm -rf {} \;
	rm -rf $(TARGET) $(TARGET_DEBUG) $(TARGET_TEST) $(TARGET_TESTDEBUG) $(TARGET_QA) $(TARGET_QADEBUG)

ifeq (.depend,$(wildcard .depend))
include .depend
endif
