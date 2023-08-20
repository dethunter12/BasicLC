/*
 Navicat Premium Data Transfer

 Source Server         : centos-dev
 Source Server Type    : MySQL
 Source Server Version : 50173
 Source Host           : 192.168.0.44:3306
 Source Schema         : spec_data

 Target Server Type    : MySQL
 Target Server Version : 50173
 File Encoding         : 65001

 Date: 24/03/2023 21:10:30
*/

SET NAMES utf8;
SET FOREIGN_KEY_CHECKS = 0;

-- ----------------------------
-- Table structure for t_domination_config
-- ----------------------------
DROP TABLE IF EXISTS `t_domination_config`;
CREATE TABLE `t_domination_config`  (
  `a_index` int(20) NOT NULL AUTO_INCREMENT,
  `a_zone` int(11) NOT NULL DEFAULT -1,
  `a_extra` int(11) NOT NULL DEFAULT 0,
  `a_time_point` int(11) NULL DEFAULT 0,
  `a_min_members` int(11) NULL DEFAULT 0,
  `a_max_points` int(11) NULL DEFAULT 0,
  `a_time_start` int(11) NULL DEFAULT 0,
  PRIMARY KEY (`a_index`) USING BTREE
) ENGINE = MyISAM AUTO_INCREMENT = 2 CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Fixed;

-- ----------------------------
-- Records of t_domination_config
-- ----------------------------
INSERT INTO `t_domination_config` VALUES (1, 7, 14, 5, 2, 200, 1);

SET FOREIGN_KEY_CHECKS = 1;
