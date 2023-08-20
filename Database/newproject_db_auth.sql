/*
 Navicat Premium Data Transfer

 Source Server         : local
 Source Server Type    : MySQL
 Source Server Version : 100422
 Source Host           : localhost:3306
 Source Schema         : newproject_db_auth

 Target Server Type    : MySQL
 Target Server Version : 100422
 File Encoding         : 65001

 Date: 05/10/2022 14:45:48
*/

SET NAMES utf8mb4;
SET FOREIGN_KEY_CHECKS = 0;

-- ----------------------------
-- Table structure for bg_user
-- ----------------------------
DROP TABLE IF EXISTS `bg_user`;
CREATE TABLE `bg_user`  (
  `user_code` int UNSIGNED NOT NULL AUTO_INCREMENT,
  `user_id` varchar(30) CHARACTER SET latin1 COLLATE latin1_swedish_ci NOT NULL DEFAULT '0',
  `truepasswd` varchar(30) CHARACTER SET latin1 COLLATE latin1_swedish_ci NULL DEFAULT NULL,
  `passwd` varchar(200) CHARACTER SET latin1 COLLATE latin1_swedish_ci NOT NULL DEFAULT '0',
  `chk_tester` char(1) CHARACTER SET latin1 COLLATE latin1_swedish_ci NOT NULL DEFAULT 'N',
  `jumin` varchar(20) CHARACTER SET latin1 COLLATE latin1_swedish_ci NULL DEFAULT '0',
  `chk_service` char(1) CHARACTER SET latin1 COLLATE latin1_swedish_ci NULL DEFAULT 'Y',
  `partner_id` char(2) CHARACTER SET latin1 COLLATE latin1_swedish_ci NOT NULL DEFAULT 'LC',
  `active_passwd` varchar(15) CHARACTER SET latin1 COLLATE latin1_swedish_ci NOT NULL DEFAULT '0',
  `active_time` datetime(0) NOT NULL DEFAULT '0000-00-00 00:00:00',
  `create_date` datetime(0) NOT NULL DEFAULT '0000-00-00 00:00:00',
  `email` varchar(100) CHARACTER SET latin1 COLLATE latin1_swedish_ci NULL DEFAULT NULL,
  `ip` varchar(20) CHARACTER SET latin1 COLLATE latin1_swedish_ci NULL DEFAULT NULL,
  `hashigh` smallint NULL DEFAULT NULL,
  `send` int NULL DEFAULT 0,
  `question` varchar(200) CHARACTER SET latin1 COLLATE latin1_swedish_ci NULL DEFAULT NULL,
  `answer` varchar(200) CHARACTER SET latin1 COLLATE latin1_swedish_ci NULL DEFAULT NULL,
  `cash` int NOT NULL DEFAULT 0,
  `team` int NOT NULL DEFAULT 0,
  `refby` varchar(30) CHARACTER SET latin1 COLLATE latin1_swedish_ci NULL DEFAULT NULL,
  `cashused` int NULL DEFAULT 0,
  `cashtotalused` int NOT NULL DEFAULT 0,
  `event_id` int NULL DEFAULT 1,
  `tier` int NULL DEFAULT 0,
  `write_time` int NULL DEFAULT NULL,
  `used_all` int UNSIGNED NULL DEFAULT NULL,
  `a_ip` varchar(20) CHARACTER SET latin1 COLLATE latin1_swedish_ci NULL DEFAULT NULL,
  `securekey` varchar(255) CHARACTER SET latin1 COLLATE latin1_swedish_ci NULL DEFAULT NULL,
  `a_enabled` int NULL DEFAULT 0,
  `chk_closebeta` varchar(1) CHARACTER SET latin1 COLLATE latin1_swedish_ci NULL DEFAULT NULL,
  `a_adminstatus` int NULL DEFAULT 0,
  `UserSession` varchar(255) CHARACTER SET latin1 COLLATE latin1_swedish_ci NULL DEFAULT NULL,
  `lastUpdated` varchar(255) CHARACTER SET latin1 COLLATE latin1_swedish_ci NULL DEFAULT NULL,
  `emailvalid` int NULL DEFAULT NULL,
  `activated` int NULL DEFAULT 1,
  `register_passwd` varchar(30) CHARACTER SET latin1 COLLATE latin1_swedish_ci NULL DEFAULT NULL,
  `secret_question` varchar(100) CHARACTER SET latin1 COLLATE latin1_swedish_ci NULL DEFAULT NULL,
  `secret_answer` varchar(50) CHARACTER SET latin1 COLLATE latin1_swedish_ci NULL DEFAULT NULL,
  `a_gametype` varchar(25) CHARACTER SET latin1 COLLATE latin1_swedish_ci NULL DEFAULT NULL,
  `a_specialsw` varchar(25) CHARACTER SET latin1 COLLATE latin1_swedish_ci NULL DEFAULT NULL,
  `a_special` varchar(25) CHARACTER SET latin1 COLLATE latin1_swedish_ci NULL DEFAULT NULL,
  `update_time` datetime(0) NULL DEFAULT NULL,
  `register_email` varchar(100) CHARACTER SET latin1 COLLATE latin1_swedish_ci NULL DEFAULT NULL,
  `access_level` int NULL DEFAULT NULL,
  `loyal_points` int NOT NULL DEFAULT 0,
  `loyal_points_time` int NOT NULL DEFAULT 0,
  `vote_times` varchar(50) CHARACTER SET latin1 COLLATE latin1_swedish_ci NOT NULL DEFAULT '0',
  `passwd_plain` varchar(15) CHARACTER SET latin1 COLLATE latin1_swedish_ci NOT NULL DEFAULT '',
  `blocked` int NULL DEFAULT 0,
  `token` varchar(255) CHARACTER SET latin1 COLLATE latin1_swedish_ci NOT NULL DEFAULT '0',
  `web_admin` int NULL DEFAULT 0,
  `deletion_token` varchar(40) CHARACTER SET latin1 COLLATE latin1_swedish_ci NOT NULL DEFAULT '0',
  `passlost_token` varchar(40) CHARACTER SET latin1 COLLATE latin1_swedish_ci NOT NULL DEFAULT '0',
  `email_token` varchar(40) CHARACTER SET latin1 COLLATE latin1_swedish_ci NOT NULL DEFAULT '0',
  `new_email` varchar(64) CHARACTER SET latin1 COLLATE latin1_swedish_ci NOT NULL DEFAULT '0',
  `status` varchar(8) CHARACTER SET latin1 COLLATE latin1_swedish_ci NOT NULL DEFAULT 'OK',
  `social_id` varchar(13) CHARACTER SET latin1 COLLATE latin1_swedish_ci NOT NULL DEFAULT '0',
  `ban_time` datetime(0) NOT NULL DEFAULT '0000-00-00 00:00:00',
  `cash_event` int NOT NULL DEFAULT 0,
  PRIMARY KEY (`user_code`) USING BTREE,
  UNIQUE INDEX `user_id`(`user_id`) USING BTREE,
  INDEX `passwd`(`passwd`) USING BTREE
) ENGINE = MyISAM AUTO_INCREMENT = 5 CHARACTER SET = latin1 COLLATE = latin1_swedish_ci ROW_FORMAT = DYNAMIC;

-- ----------------------------
-- Records of bg_user
-- ----------------------------
INSERT INTO `bg_user` VALUES (1, 'Aiz491', '', '98576ab8fef10e6395db76241a3c74fb', 'N', '0', 'Y', 'LC', '0', '2022-09-04 19:21:38', '0000-00-00 00:00:00', 'anthonykennedy1105@gmail.com', NULL, NULL, 0, NULL, NULL, 100512, 0, NULL, 0, 0, 1, 0, NULL, NULL, NULL, NULL, 0, NULL, 0, NULL, NULL, NULL, 1, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, 0, 0, '0', '', 0, '0', 0, '0', '0', '0', '0', 'OK', '0', '0000-00-00 00:00:00', 0);
INSERT INTO `bg_user` VALUES (2, 'Nate', NULL, 'a5d0b27b0b29be41b0196f2461035fe2', 'N', '0', 'Y', 'LC', '0', '0000-00-00 00:00:00', '0000-00-00 00:00:00', NULL, NULL, NULL, 0, NULL, NULL, 0, 0, NULL, 0, 0, 1, 0, NULL, NULL, NULL, NULL, 0, NULL, 0, NULL, NULL, NULL, 1, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, 0, 0, '0', '', 0, '0', 0, '0', '0', '0', '0', 'OK', '0', '0000-00-00 00:00:00', 0);

-- ----------------------------
-- Table structure for bg_user_active
-- ----------------------------
DROP TABLE IF EXISTS `bg_user_active`;
CREATE TABLE `bg_user_active`  (
  `active_index` int UNSIGNED NOT NULL AUTO_INCREMENT,
  `active_code` int UNSIGNED NOT NULL DEFAULT 0,
  `active_game` char(3) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL DEFAULT '24',
  `active_time` datetime(0) NOT NULL DEFAULT '2006-04-20 00:00:00',
  `active_passwd` varchar(50) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL DEFAULT '',
  PRIMARY KEY (`active_index`) USING BTREE,
  UNIQUE INDEX `idx_user`(`active_code`, `active_game`) USING BTREE,
  INDEX `active_index`(`active_index`) USING BTREE
) ENGINE = MyISAM AUTO_INCREMENT = 1 CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Records of bg_user_active
-- ----------------------------

-- ----------------------------
-- Table structure for t_connect_count
-- ----------------------------
DROP TABLE IF EXISTS `t_connect_count`;
CREATE TABLE `t_connect_count`  (
  `a_index` int UNSIGNED NOT NULL AUTO_INCREMENT,
  `a_count` int UNSIGNED NOT NULL DEFAULT 0,
  `a_date` datetime(0) NULL DEFAULT NULL,
  `a_server` int NULL DEFAULT 0,
  `a_sub_num` int UNSIGNED NULL DEFAULT 0,
  `a_zone_num` int UNSIGNED NOT NULL DEFAULT 0,
  `a_area` char(2) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT 'BJ',
  `a_level_count` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
  PRIMARY KEY (`a_index`) USING BTREE,
  INDEX `a_sub_num`(`a_sub_num`, `a_zone_num`) USING BTREE,
  INDEX `a_date`(`a_date`) USING BTREE
) ENGINE = MyISAM AUTO_INCREMENT = 3355 CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Records of t_connect_count
-- ----------------------------
INSERT INTO `t_connect_count` VALUES (1, 0, '2022-10-04 19:50:00', 1, 1, 0, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2, 0, '2022-10-04 19:50:00', 1, 1, 1, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (3, 0, '2022-10-04 19:50:00', 1, 1, 2, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (4, 0, '2022-10-04 19:50:00', 1, 1, 3, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (5, 0, '2022-10-04 19:50:00', 1, 1, 4, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (6, 0, '2022-10-04 19:50:00', 1, 1, 5, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (7, 0, '2022-10-04 19:50:00', 1, 1, 6, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (8, 0, '2022-10-04 19:50:00', 1, 1, 7, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (9, 0, '2022-10-04 19:50:00', 1, 1, 8, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (10, 0, '2022-10-04 19:50:00', 1, 1, 9, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (11, 0, '2022-10-04 19:50:00', 1, 1, 10, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (12, 0, '2022-10-04 19:50:00', 1, 1, 11, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (13, 0, '2022-10-04 19:50:00', 1, 1, 12, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (14, 0, '2022-10-04 19:50:00', 1, 1, 13, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (15, 0, '2022-10-04 19:50:00', 1, 1, 14, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (16, 0, '2022-10-04 19:50:00', 1, 1, 15, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (17, 0, '2022-10-04 19:50:00', 1, 1, 16, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (18, 0, '2022-10-04 19:50:00', 1, 1, 17, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (19, 0, '2022-10-04 19:50:00', 1, 1, 18, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (20, 0, '2022-10-04 19:50:00', 1, 1, 19, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (21, 0, '2022-10-04 19:50:00', 1, 1, 20, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (22, 0, '2022-10-04 19:50:00', 1, 1, 21, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (23, 0, '2022-10-04 19:50:00', 1, 1, 22, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (24, 0, '2022-10-04 19:50:00', 1, 1, 23, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (25, 0, '2022-10-04 19:50:00', 1, 1, 24, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (26, 0, '2022-10-04 19:50:00', 1, 1, 25, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (27, 0, '2022-10-04 19:50:00', 1, 1, 26, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (28, 0, '2022-10-04 19:50:00', 1, 1, 27, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (29, 0, '2022-10-04 19:50:00', 1, 1, 28, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (30, 0, '2022-10-04 19:50:00', 1, 1, 29, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (31, 0, '2022-10-04 19:50:00', 1, 1, 30, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (32, 0, '2022-10-04 19:50:00', 1, 1, 31, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (33, 0, '2022-10-04 19:50:00', 1, 1, 32, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (34, 0, '2022-10-04 19:50:00', 1, 1, 33, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (35, 0, '2022-10-04 19:50:00', 1, 1, 34, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (36, 0, '2022-10-04 19:50:00', 1, 1, 35, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (37, 0, '2022-10-04 19:50:00', 1, 1, 36, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (38, 0, '2022-10-04 19:50:00', 1, 1, 37, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (39, 0, '2022-10-04 19:50:00', 1, 1, 38, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (40, 0, '2022-10-04 19:50:00', 1, 1, 39, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (41, 0, '2022-10-04 19:50:00', 1, 1, 40, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (42, 0, '2022-10-04 19:50:00', 1, 1, 41, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (43, 0, '2022-10-04 19:50:00', 1, 1, 42, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (44, 0, '2022-10-04 19:50:00', 1, 2, 0, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (45, 0, '2022-10-04 19:50:00', 1, 2, 1, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (46, 0, '2022-10-04 19:50:00', 1, 2, 2, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (47, 0, '2022-10-04 19:50:00', 1, 2, 3, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (48, 0, '2022-10-04 19:50:00', 1, 2, 4, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (49, 0, '2022-10-04 19:50:00', 1, 2, 5, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (50, 0, '2022-10-04 19:50:00', 1, 2, 6, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (51, 0, '2022-10-04 19:50:00', 1, 2, 7, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (52, 0, '2022-10-04 19:50:00', 1, 2, 8, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (53, 0, '2022-10-04 19:50:00', 1, 2, 9, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (54, 0, '2022-10-04 19:50:00', 1, 2, 10, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (55, 0, '2022-10-04 19:50:00', 1, 2, 11, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (56, 0, '2022-10-04 19:50:00', 1, 2, 12, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (57, 0, '2022-10-04 19:50:00', 1, 2, 13, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (58, 0, '2022-10-04 19:50:00', 1, 2, 14, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (59, 0, '2022-10-04 19:50:00', 1, 2, 15, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (60, 0, '2022-10-04 19:50:00', 1, 2, 16, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (61, 0, '2022-10-04 19:50:00', 1, 2, 17, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (62, 0, '2022-10-04 19:50:00', 1, 2, 18, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (63, 0, '2022-10-04 19:50:00', 1, 2, 19, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (64, 0, '2022-10-04 19:50:00', 1, 2, 20, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (65, 0, '2022-10-04 19:50:00', 1, 2, 21, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (66, 0, '2022-10-04 19:50:00', 1, 2, 22, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (67, 0, '2022-10-04 19:50:00', 1, 2, 23, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (68, 0, '2022-10-04 19:50:00', 1, 2, 24, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (69, 0, '2022-10-04 19:50:00', 1, 2, 25, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (70, 0, '2022-10-04 19:50:00', 1, 2, 26, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (71, 0, '2022-10-04 19:50:00', 1, 2, 27, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (72, 0, '2022-10-04 19:50:00', 1, 2, 28, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (73, 0, '2022-10-04 19:50:00', 1, 2, 29, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (74, 0, '2022-10-04 19:50:00', 1, 2, 30, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (75, 0, '2022-10-04 19:50:00', 1, 2, 31, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (76, 0, '2022-10-04 19:50:00', 1, 2, 32, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (77, 0, '2022-10-04 19:50:00', 1, 2, 33, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (78, 0, '2022-10-04 19:50:00', 1, 2, 34, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (79, 0, '2022-10-04 19:50:00', 1, 2, 35, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (80, 0, '2022-10-04 19:50:00', 1, 2, 36, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (81, 0, '2022-10-04 19:50:00', 1, 2, 37, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (82, 0, '2022-10-04 19:50:00', 1, 2, 38, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (83, 0, '2022-10-04 19:50:00', 1, 2, 39, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (84, 0, '2022-10-04 19:50:00', 1, 2, 40, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (85, 0, '2022-10-04 19:50:00', 1, 2, 41, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (86, 0, '2022-10-04 19:50:00', 1, 2, 42, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (87, 0, '2022-10-04 19:50:00', 1, 3, 0, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (88, 0, '2022-10-04 19:50:00', 1, 3, 1, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (89, 0, '2022-10-04 19:50:00', 1, 3, 2, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (90, 0, '2022-10-04 19:50:00', 1, 3, 3, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (91, 0, '2022-10-04 19:50:00', 1, 3, 4, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (92, 0, '2022-10-04 19:50:00', 1, 3, 5, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (93, 0, '2022-10-04 19:50:00', 1, 3, 6, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (94, 0, '2022-10-04 19:50:00', 1, 3, 7, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (95, 0, '2022-10-04 19:50:00', 1, 3, 8, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (96, 0, '2022-10-04 19:50:00', 1, 3, 9, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (97, 0, '2022-10-04 19:50:00', 1, 3, 10, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (98, 0, '2022-10-04 19:50:00', 1, 3, 11, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (99, 0, '2022-10-04 19:50:00', 1, 3, 12, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (100, 0, '2022-10-04 19:50:00', 1, 3, 13, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (101, 0, '2022-10-04 19:50:00', 1, 3, 14, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (102, 0, '2022-10-04 19:50:00', 1, 3, 15, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (103, 0, '2022-10-04 19:50:00', 1, 3, 16, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (104, 0, '2022-10-04 19:50:00', 1, 3, 17, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (105, 0, '2022-10-04 19:50:00', 1, 3, 18, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (106, 0, '2022-10-04 19:50:00', 1, 3, 19, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (107, 0, '2022-10-04 19:50:00', 1, 3, 20, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (108, 0, '2022-10-04 19:50:00', 1, 3, 21, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (109, 0, '2022-10-04 19:50:00', 1, 3, 22, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (110, 0, '2022-10-04 19:50:00', 1, 3, 23, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (111, 0, '2022-10-04 19:50:00', 1, 3, 24, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (112, 0, '2022-10-04 19:50:00', 1, 3, 25, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (113, 0, '2022-10-04 19:50:00', 1, 3, 26, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (114, 0, '2022-10-04 19:50:00', 1, 3, 27, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (115, 0, '2022-10-04 19:50:00', 1, 3, 28, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (116, 0, '2022-10-04 19:50:00', 1, 3, 29, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (117, 0, '2022-10-04 19:50:00', 1, 3, 30, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (118, 0, '2022-10-04 19:50:00', 1, 3, 31, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (119, 0, '2022-10-04 19:50:00', 1, 3, 32, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (120, 0, '2022-10-04 19:50:00', 1, 3, 33, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (121, 0, '2022-10-04 19:50:00', 1, 3, 34, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (122, 0, '2022-10-04 19:50:00', 1, 3, 35, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (123, 0, '2022-10-04 19:50:00', 1, 3, 36, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (124, 0, '2022-10-04 19:50:00', 1, 3, 37, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (125, 0, '2022-10-04 19:50:00', 1, 3, 38, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (126, 0, '2022-10-04 19:50:00', 1, 3, 39, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (127, 0, '2022-10-04 19:50:00', 1, 3, 40, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (128, 0, '2022-10-04 19:50:00', 1, 3, 41, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (129, 0, '2022-10-04 19:50:00', 1, 3, 42, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (130, 0, '2022-10-04 19:55:00', 1, 1, 0, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (131, 0, '2022-10-04 19:55:00', 1, 1, 1, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (132, 0, '2022-10-04 19:55:00', 1, 1, 2, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (133, 0, '2022-10-04 19:55:00', 1, 1, 3, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (134, 0, '2022-10-04 19:55:00', 1, 1, 4, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (135, 0, '2022-10-04 19:55:00', 1, 1, 5, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (136, 0, '2022-10-04 19:55:00', 1, 1, 6, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (137, 0, '2022-10-04 19:55:00', 1, 1, 7, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (138, 0, '2022-10-04 19:55:00', 1, 1, 8, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (139, 0, '2022-10-04 19:55:00', 1, 1, 9, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (140, 0, '2022-10-04 19:55:00', 1, 1, 10, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (141, 0, '2022-10-04 19:55:00', 1, 1, 11, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (142, 0, '2022-10-04 19:55:00', 1, 1, 12, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (143, 0, '2022-10-04 19:55:00', 1, 1, 13, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (144, 0, '2022-10-04 19:55:00', 1, 1, 14, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (145, 0, '2022-10-04 19:55:00', 1, 1, 15, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (146, 0, '2022-10-04 19:55:00', 1, 1, 16, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (147, 0, '2022-10-04 19:55:00', 1, 1, 17, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (148, 0, '2022-10-04 19:55:00', 1, 1, 18, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (149, 0, '2022-10-04 19:55:00', 1, 1, 19, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (150, 0, '2022-10-04 19:55:00', 1, 1, 20, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (151, 0, '2022-10-04 19:55:00', 1, 1, 21, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (152, 0, '2022-10-04 19:55:00', 1, 1, 22, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (153, 0, '2022-10-04 19:55:00', 1, 1, 23, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (154, 0, '2022-10-04 19:55:00', 1, 1, 24, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (155, 0, '2022-10-04 19:55:00', 1, 1, 25, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (156, 0, '2022-10-04 19:55:00', 1, 1, 26, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (157, 0, '2022-10-04 19:55:00', 1, 1, 27, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (158, 0, '2022-10-04 19:55:00', 1, 1, 28, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (159, 0, '2022-10-04 19:55:00', 1, 1, 29, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (160, 0, '2022-10-04 19:55:00', 1, 1, 30, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (161, 0, '2022-10-04 19:55:00', 1, 1, 31, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (162, 0, '2022-10-04 19:55:00', 1, 1, 32, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (163, 0, '2022-10-04 19:55:00', 1, 1, 33, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (164, 0, '2022-10-04 19:55:00', 1, 1, 34, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (165, 0, '2022-10-04 19:55:00', 1, 1, 35, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (166, 0, '2022-10-04 19:55:00', 1, 1, 36, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (167, 0, '2022-10-04 19:55:00', 1, 1, 37, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (168, 0, '2022-10-04 19:55:00', 1, 1, 38, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (169, 0, '2022-10-04 19:55:00', 1, 1, 39, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (170, 0, '2022-10-04 19:55:00', 1, 1, 40, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (171, 0, '2022-10-04 19:55:00', 1, 1, 41, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (172, 0, '2022-10-04 19:55:00', 1, 1, 42, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (173, 0, '2022-10-04 19:55:00', 1, 2, 0, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (174, 0, '2022-10-04 19:55:00', 1, 2, 1, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (175, 0, '2022-10-04 19:55:00', 1, 2, 2, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (176, 0, '2022-10-04 19:55:00', 1, 2, 3, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (177, 0, '2022-10-04 19:55:00', 1, 2, 4, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (178, 0, '2022-10-04 19:55:00', 1, 2, 5, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (179, 0, '2022-10-04 19:55:00', 1, 2, 6, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (180, 0, '2022-10-04 19:55:00', 1, 2, 7, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (181, 0, '2022-10-04 19:55:00', 1, 2, 8, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (182, 0, '2022-10-04 19:55:00', 1, 2, 9, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (183, 0, '2022-10-04 19:55:00', 1, 2, 10, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (184, 0, '2022-10-04 19:55:00', 1, 2, 11, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (185, 0, '2022-10-04 19:55:00', 1, 2, 12, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (186, 0, '2022-10-04 19:55:00', 1, 2, 13, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (187, 0, '2022-10-04 19:55:00', 1, 2, 14, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (188, 0, '2022-10-04 19:55:00', 1, 2, 15, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (189, 0, '2022-10-04 19:55:00', 1, 2, 16, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (190, 0, '2022-10-04 19:55:00', 1, 2, 17, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (191, 0, '2022-10-04 19:55:00', 1, 2, 18, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (192, 0, '2022-10-04 19:55:00', 1, 2, 19, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (193, 0, '2022-10-04 19:55:00', 1, 2, 20, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (194, 0, '2022-10-04 19:55:00', 1, 2, 21, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (195, 0, '2022-10-04 19:55:00', 1, 2, 22, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (196, 0, '2022-10-04 19:55:00', 1, 2, 23, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (197, 0, '2022-10-04 19:55:00', 1, 2, 24, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (198, 0, '2022-10-04 19:55:00', 1, 2, 25, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (199, 0, '2022-10-04 19:55:00', 1, 2, 26, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (200, 0, '2022-10-04 19:55:00', 1, 2, 27, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (201, 0, '2022-10-04 19:55:00', 1, 2, 28, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (202, 0, '2022-10-04 19:55:00', 1, 2, 29, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (203, 0, '2022-10-04 19:55:00', 1, 2, 30, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (204, 0, '2022-10-04 19:55:00', 1, 2, 31, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (205, 0, '2022-10-04 19:55:00', 1, 2, 32, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (206, 0, '2022-10-04 19:55:00', 1, 2, 33, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (207, 0, '2022-10-04 19:55:00', 1, 2, 34, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (208, 0, '2022-10-04 19:55:00', 1, 2, 35, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (209, 0, '2022-10-04 19:55:00', 1, 2, 36, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (210, 0, '2022-10-04 19:55:00', 1, 2, 37, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (211, 0, '2022-10-04 19:55:00', 1, 2, 38, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (212, 0, '2022-10-04 19:55:00', 1, 2, 39, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (213, 0, '2022-10-04 19:55:00', 1, 2, 40, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (214, 0, '2022-10-04 19:55:00', 1, 2, 41, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (215, 0, '2022-10-04 19:55:00', 1, 2, 42, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (216, 0, '2022-10-04 19:55:00', 1, 3, 0, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (217, 0, '2022-10-04 19:55:00', 1, 3, 1, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (218, 0, '2022-10-04 19:55:00', 1, 3, 2, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (219, 0, '2022-10-04 19:55:00', 1, 3, 3, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (220, 0, '2022-10-04 19:55:00', 1, 3, 4, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (221, 0, '2022-10-04 19:55:00', 1, 3, 5, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (222, 0, '2022-10-04 19:55:00', 1, 3, 6, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (223, 0, '2022-10-04 19:55:00', 1, 3, 7, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (224, 0, '2022-10-04 19:55:00', 1, 3, 8, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (225, 0, '2022-10-04 19:55:00', 1, 3, 9, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (226, 0, '2022-10-04 19:55:00', 1, 3, 10, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (227, 0, '2022-10-04 19:55:00', 1, 3, 11, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (228, 0, '2022-10-04 19:55:00', 1, 3, 12, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (229, 0, '2022-10-04 19:55:00', 1, 3, 13, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (230, 0, '2022-10-04 19:55:00', 1, 3, 14, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (231, 0, '2022-10-04 19:55:00', 1, 3, 15, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (232, 0, '2022-10-04 19:55:00', 1, 3, 16, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (233, 0, '2022-10-04 19:55:00', 1, 3, 17, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (234, 0, '2022-10-04 19:55:00', 1, 3, 18, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (235, 0, '2022-10-04 19:55:00', 1, 3, 19, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (236, 0, '2022-10-04 19:55:00', 1, 3, 20, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (237, 0, '2022-10-04 19:55:00', 1, 3, 21, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (238, 0, '2022-10-04 19:55:00', 1, 3, 22, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (239, 0, '2022-10-04 19:55:00', 1, 3, 23, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (240, 0, '2022-10-04 19:55:00', 1, 3, 24, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (241, 0, '2022-10-04 19:55:00', 1, 3, 25, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (242, 0, '2022-10-04 19:55:00', 1, 3, 26, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (243, 0, '2022-10-04 19:55:00', 1, 3, 27, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (244, 0, '2022-10-04 19:55:00', 1, 3, 28, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (245, 0, '2022-10-04 19:55:00', 1, 3, 29, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (246, 0, '2022-10-04 19:55:00', 1, 3, 30, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (247, 0, '2022-10-04 19:55:00', 1, 3, 31, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (248, 0, '2022-10-04 19:55:00', 1, 3, 32, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (249, 0, '2022-10-04 19:55:00', 1, 3, 33, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (250, 0, '2022-10-04 19:55:00', 1, 3, 34, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (251, 0, '2022-10-04 19:55:00', 1, 3, 35, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (252, 0, '2022-10-04 19:55:00', 1, 3, 36, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (253, 0, '2022-10-04 19:55:00', 1, 3, 37, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (254, 0, '2022-10-04 19:55:00', 1, 3, 38, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (255, 0, '2022-10-04 19:55:00', 1, 3, 39, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (256, 0, '2022-10-04 19:55:00', 1, 3, 40, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (257, 0, '2022-10-04 19:55:00', 1, 3, 41, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (258, 0, '2022-10-04 19:55:00', 1, 3, 42, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (259, 0, '2022-10-05 12:45:00', 1, 1, 0, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (260, 0, '2022-10-05 12:45:00', 1, 1, 1, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (261, 0, '2022-10-05 12:45:00', 1, 1, 2, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (262, 0, '2022-10-05 12:45:00', 1, 1, 3, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (263, 0, '2022-10-05 12:45:00', 1, 1, 4, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (264, 0, '2022-10-05 12:45:00', 1, 1, 5, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (265, 0, '2022-10-05 12:45:00', 1, 1, 6, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (266, 0, '2022-10-05 12:45:00', 1, 1, 7, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (267, 0, '2022-10-05 12:45:00', 1, 1, 8, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (268, 0, '2022-10-05 12:45:00', 1, 1, 9, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (269, 0, '2022-10-05 12:45:00', 1, 1, 10, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (270, 0, '2022-10-05 12:45:00', 1, 1, 11, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (271, 0, '2022-10-05 12:45:00', 1, 1, 12, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (272, 0, '2022-10-05 12:45:00', 1, 1, 13, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (273, 0, '2022-10-05 12:45:00', 1, 1, 14, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (274, 0, '2022-10-05 12:45:00', 1, 1, 15, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (275, 0, '2022-10-05 12:45:00', 1, 1, 16, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (276, 0, '2022-10-05 12:45:00', 1, 1, 17, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (277, 0, '2022-10-05 12:45:00', 1, 1, 18, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (278, 0, '2022-10-05 12:45:00', 1, 1, 19, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (279, 0, '2022-10-05 12:45:00', 1, 1, 20, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (280, 0, '2022-10-05 12:45:00', 1, 1, 21, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (281, 0, '2022-10-05 12:45:00', 1, 1, 22, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (282, 0, '2022-10-05 12:45:00', 1, 1, 23, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (283, 0, '2022-10-05 12:45:00', 1, 1, 24, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (284, 0, '2022-10-05 12:45:00', 1, 1, 25, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (285, 0, '2022-10-05 12:45:00', 1, 1, 26, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (286, 0, '2022-10-05 12:45:00', 1, 1, 27, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (287, 0, '2022-10-05 12:45:00', 1, 1, 28, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (288, 0, '2022-10-05 12:45:00', 1, 1, 29, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (289, 0, '2022-10-05 12:45:00', 1, 1, 30, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (290, 0, '2022-10-05 12:45:00', 1, 1, 31, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (291, 0, '2022-10-05 12:45:00', 1, 1, 32, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (292, 0, '2022-10-05 12:45:00', 1, 1, 33, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (293, 0, '2022-10-05 12:45:00', 1, 1, 34, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (294, 0, '2022-10-05 12:45:00', 1, 1, 35, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (295, 0, '2022-10-05 12:45:00', 1, 1, 36, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (296, 0, '2022-10-05 12:45:00', 1, 1, 37, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (297, 0, '2022-10-05 12:45:00', 1, 1, 38, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (298, 0, '2022-10-05 12:45:00', 1, 1, 39, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (299, 0, '2022-10-05 12:45:00', 1, 1, 40, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (300, 0, '2022-10-05 12:45:00', 1, 1, 41, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (301, 0, '2022-10-05 12:45:00', 1, 1, 42, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (302, 0, '2022-10-05 12:45:00', 1, 2, 0, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (303, 0, '2022-10-05 12:45:00', 1, 2, 1, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (304, 0, '2022-10-05 12:45:00', 1, 2, 2, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (305, 0, '2022-10-05 12:45:00', 1, 2, 3, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (306, 0, '2022-10-05 12:45:00', 1, 2, 4, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (307, 0, '2022-10-05 12:45:00', 1, 2, 5, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (308, 0, '2022-10-05 12:45:00', 1, 2, 6, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (309, 0, '2022-10-05 12:45:00', 1, 2, 7, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (310, 0, '2022-10-05 12:45:00', 1, 2, 8, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (311, 0, '2022-10-05 12:45:00', 1, 2, 9, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (312, 0, '2022-10-05 12:45:00', 1, 2, 10, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (313, 0, '2022-10-05 12:45:00', 1, 2, 11, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (314, 0, '2022-10-05 12:45:00', 1, 2, 12, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (315, 0, '2022-10-05 12:45:00', 1, 2, 13, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (316, 0, '2022-10-05 12:45:00', 1, 2, 14, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (317, 0, '2022-10-05 12:45:00', 1, 2, 15, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (318, 0, '2022-10-05 12:45:00', 1, 2, 16, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (319, 0, '2022-10-05 12:45:00', 1, 2, 17, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (320, 0, '2022-10-05 12:45:00', 1, 2, 18, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (321, 0, '2022-10-05 12:45:00', 1, 2, 19, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (322, 0, '2022-10-05 12:45:00', 1, 2, 20, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (323, 0, '2022-10-05 12:45:00', 1, 2, 21, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (324, 0, '2022-10-05 12:45:00', 1, 2, 22, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (325, 0, '2022-10-05 12:45:00', 1, 2, 23, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (326, 0, '2022-10-05 12:45:00', 1, 2, 24, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (327, 0, '2022-10-05 12:45:00', 1, 2, 25, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (328, 0, '2022-10-05 12:45:00', 1, 2, 26, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (329, 0, '2022-10-05 12:45:00', 1, 2, 27, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (330, 0, '2022-10-05 12:45:00', 1, 2, 28, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (331, 0, '2022-10-05 12:45:00', 1, 2, 29, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (332, 0, '2022-10-05 12:45:00', 1, 2, 30, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (333, 0, '2022-10-05 12:45:00', 1, 2, 31, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (334, 0, '2022-10-05 12:45:00', 1, 2, 32, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (335, 0, '2022-10-05 12:45:00', 1, 2, 33, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (336, 0, '2022-10-05 12:45:00', 1, 2, 34, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (337, 0, '2022-10-05 12:45:00', 1, 2, 35, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (338, 0, '2022-10-05 12:45:00', 1, 2, 36, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (339, 0, '2022-10-05 12:45:00', 1, 2, 37, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (340, 0, '2022-10-05 12:45:00', 1, 2, 38, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (341, 0, '2022-10-05 12:45:00', 1, 2, 39, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (342, 0, '2022-10-05 12:45:00', 1, 2, 40, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (343, 0, '2022-10-05 12:45:00', 1, 2, 41, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (344, 0, '2022-10-05 12:45:00', 1, 2, 42, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (345, 0, '2022-10-05 12:45:00', 1, 3, 0, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (346, 0, '2022-10-05 12:45:00', 1, 3, 1, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (347, 0, '2022-10-05 12:45:00', 1, 3, 2, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (348, 0, '2022-10-05 12:45:00', 1, 3, 3, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (349, 0, '2022-10-05 12:45:00', 1, 3, 4, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (350, 0, '2022-10-05 12:45:00', 1, 3, 5, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (351, 0, '2022-10-05 12:45:00', 1, 3, 6, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (352, 0, '2022-10-05 12:45:00', 1, 3, 7, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (353, 0, '2022-10-05 12:45:00', 1, 3, 8, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (354, 0, '2022-10-05 12:45:00', 1, 3, 9, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (355, 0, '2022-10-05 12:45:00', 1, 3, 10, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (356, 0, '2022-10-05 12:45:00', 1, 3, 11, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (357, 0, '2022-10-05 12:45:00', 1, 3, 12, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (358, 0, '2022-10-05 12:45:00', 1, 3, 13, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (359, 0, '2022-10-05 12:45:00', 1, 3, 14, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (360, 0, '2022-10-05 12:45:00', 1, 3, 15, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (361, 0, '2022-10-05 12:45:00', 1, 3, 16, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (362, 0, '2022-10-05 12:45:00', 1, 3, 17, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (363, 0, '2022-10-05 12:45:00', 1, 3, 18, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (364, 0, '2022-10-05 12:45:00', 1, 3, 19, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (365, 0, '2022-10-05 12:45:00', 1, 3, 20, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (366, 0, '2022-10-05 12:45:00', 1, 3, 21, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (367, 0, '2022-10-05 12:45:00', 1, 3, 22, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (368, 0, '2022-10-05 12:45:00', 1, 3, 23, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (369, 0, '2022-10-05 12:45:00', 1, 3, 24, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (370, 0, '2022-10-05 12:45:00', 1, 3, 25, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (371, 0, '2022-10-05 12:45:00', 1, 3, 26, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (372, 0, '2022-10-05 12:45:00', 1, 3, 27, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (373, 0, '2022-10-05 12:45:00', 1, 3, 28, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (374, 0, '2022-10-05 12:45:00', 1, 3, 29, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (375, 0, '2022-10-05 12:45:00', 1, 3, 30, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (376, 0, '2022-10-05 12:45:00', 1, 3, 31, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (377, 0, '2022-10-05 12:45:00', 1, 3, 32, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (378, 0, '2022-10-05 12:45:00', 1, 3, 33, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (379, 0, '2022-10-05 12:45:00', 1, 3, 34, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (380, 0, '2022-10-05 12:45:00', 1, 3, 35, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (381, 0, '2022-10-05 12:45:00', 1, 3, 36, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (382, 0, '2022-10-05 12:45:00', 1, 3, 37, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (383, 0, '2022-10-05 12:45:00', 1, 3, 38, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (384, 0, '2022-10-05 12:45:00', 1, 3, 39, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (385, 0, '2022-10-05 12:45:00', 1, 3, 40, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (386, 0, '2022-10-05 12:45:00', 1, 3, 41, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (387, 0, '2022-10-05 12:45:00', 1, 3, 42, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (388, 0, '2022-10-05 12:50:00', 1, 1, 0, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (389, 0, '2022-10-05 12:50:00', 1, 1, 1, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (390, 0, '2022-10-05 12:50:00', 1, 1, 2, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (391, 0, '2022-10-05 12:50:00', 1, 1, 3, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (392, 0, '2022-10-05 12:50:00', 1, 1, 4, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (393, 0, '2022-10-05 12:50:00', 1, 1, 5, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (394, 0, '2022-10-05 12:50:00', 1, 1, 6, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (395, 0, '2022-10-05 12:50:00', 1, 1, 7, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (396, 0, '2022-10-05 12:50:00', 1, 1, 8, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (397, 0, '2022-10-05 12:50:00', 1, 1, 9, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (398, 0, '2022-10-05 12:50:00', 1, 1, 10, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (399, 0, '2022-10-05 12:50:00', 1, 1, 11, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (400, 0, '2022-10-05 12:50:00', 1, 1, 12, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (401, 0, '2022-10-05 12:50:00', 1, 1, 13, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (402, 0, '2022-10-05 12:50:00', 1, 1, 14, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (403, 0, '2022-10-05 12:50:00', 1, 1, 15, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (404, 0, '2022-10-05 12:50:00', 1, 1, 16, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (405, 0, '2022-10-05 12:50:00', 1, 1, 17, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (406, 0, '2022-10-05 12:50:00', 1, 1, 18, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (407, 0, '2022-10-05 12:50:00', 1, 1, 19, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (408, 0, '2022-10-05 12:50:00', 1, 1, 20, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (409, 0, '2022-10-05 12:50:00', 1, 1, 21, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (410, 0, '2022-10-05 12:50:00', 1, 1, 22, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (411, 0, '2022-10-05 12:50:00', 1, 1, 23, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (412, 0, '2022-10-05 12:50:00', 1, 1, 24, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (413, 0, '2022-10-05 12:50:00', 1, 1, 25, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (414, 0, '2022-10-05 12:50:00', 1, 1, 26, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (415, 0, '2022-10-05 12:50:00', 1, 1, 27, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (416, 0, '2022-10-05 12:50:00', 1, 1, 28, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (417, 0, '2022-10-05 12:50:00', 1, 1, 29, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (418, 0, '2022-10-05 12:50:00', 1, 1, 30, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (419, 0, '2022-10-05 12:50:00', 1, 1, 31, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (420, 0, '2022-10-05 12:50:00', 1, 1, 32, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (421, 0, '2022-10-05 12:50:00', 1, 1, 33, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (422, 0, '2022-10-05 12:50:00', 1, 1, 34, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (423, 0, '2022-10-05 12:50:00', 1, 1, 35, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (424, 0, '2022-10-05 12:50:00', 1, 1, 36, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (425, 0, '2022-10-05 12:50:00', 1, 1, 37, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (426, 0, '2022-10-05 12:50:00', 1, 1, 38, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (427, 0, '2022-10-05 12:50:00', 1, 1, 39, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (428, 0, '2022-10-05 12:50:00', 1, 1, 40, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (429, 0, '2022-10-05 12:50:00', 1, 1, 41, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (430, 0, '2022-10-05 12:50:00', 1, 1, 42, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (431, 0, '2022-10-05 12:50:00', 1, 2, 0, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (432, 0, '2022-10-05 12:50:00', 1, 2, 1, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (433, 0, '2022-10-05 12:50:00', 1, 2, 2, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (434, 0, '2022-10-05 12:50:00', 1, 2, 3, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (435, 0, '2022-10-05 12:50:00', 1, 2, 4, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (436, 0, '2022-10-05 12:50:00', 1, 2, 5, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (437, 0, '2022-10-05 12:50:00', 1, 2, 6, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (438, 0, '2022-10-05 12:50:00', 1, 2, 7, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (439, 0, '2022-10-05 12:50:00', 1, 2, 8, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (440, 0, '2022-10-05 12:50:00', 1, 2, 9, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (441, 0, '2022-10-05 12:50:00', 1, 2, 10, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (442, 0, '2022-10-05 12:50:00', 1, 2, 11, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (443, 0, '2022-10-05 12:50:00', 1, 2, 12, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (444, 0, '2022-10-05 12:50:00', 1, 2, 13, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (445, 0, '2022-10-05 12:50:00', 1, 2, 14, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (446, 0, '2022-10-05 12:50:00', 1, 2, 15, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (447, 0, '2022-10-05 12:50:00', 1, 2, 16, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (448, 0, '2022-10-05 12:50:00', 1, 2, 17, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (449, 0, '2022-10-05 12:50:00', 1, 2, 18, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (450, 0, '2022-10-05 12:50:00', 1, 2, 19, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (451, 0, '2022-10-05 12:50:00', 1, 2, 20, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (452, 0, '2022-10-05 12:50:00', 1, 2, 21, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (453, 0, '2022-10-05 12:50:00', 1, 2, 22, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (454, 0, '2022-10-05 12:50:00', 1, 2, 23, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (455, 0, '2022-10-05 12:50:00', 1, 2, 24, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (456, 0, '2022-10-05 12:50:00', 1, 2, 25, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (457, 0, '2022-10-05 12:50:00', 1, 2, 26, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (458, 0, '2022-10-05 12:50:00', 1, 2, 27, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (459, 0, '2022-10-05 12:50:00', 1, 2, 28, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (460, 0, '2022-10-05 12:50:00', 1, 2, 29, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (461, 0, '2022-10-05 12:50:00', 1, 2, 30, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (462, 0, '2022-10-05 12:50:00', 1, 2, 31, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (463, 0, '2022-10-05 12:50:00', 1, 2, 32, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (464, 0, '2022-10-05 12:50:00', 1, 2, 33, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (465, 0, '2022-10-05 12:50:00', 1, 2, 34, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (466, 0, '2022-10-05 12:50:00', 1, 2, 35, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (467, 0, '2022-10-05 12:50:00', 1, 2, 36, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (468, 0, '2022-10-05 12:50:00', 1, 2, 37, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (469, 0, '2022-10-05 12:50:00', 1, 2, 38, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (470, 0, '2022-10-05 12:50:00', 1, 2, 39, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (471, 0, '2022-10-05 12:50:00', 1, 2, 40, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (472, 0, '2022-10-05 12:50:00', 1, 2, 41, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (473, 0, '2022-10-05 12:50:00', 1, 2, 42, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (474, 0, '2022-10-05 12:50:00', 1, 3, 0, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (475, 0, '2022-10-05 12:50:00', 1, 3, 1, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (476, 0, '2022-10-05 12:50:00', 1, 3, 2, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (477, 0, '2022-10-05 12:50:00', 1, 3, 3, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (478, 0, '2022-10-05 12:50:00', 1, 3, 4, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (479, 0, '2022-10-05 12:50:00', 1, 3, 5, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (480, 0, '2022-10-05 12:50:00', 1, 3, 6, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (481, 0, '2022-10-05 12:50:00', 1, 3, 7, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (482, 0, '2022-10-05 12:50:00', 1, 3, 8, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (483, 0, '2022-10-05 12:50:00', 1, 3, 9, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (484, 0, '2022-10-05 12:50:00', 1, 3, 10, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (485, 0, '2022-10-05 12:50:00', 1, 3, 11, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (486, 0, '2022-10-05 12:50:00', 1, 3, 12, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (487, 0, '2022-10-05 12:50:00', 1, 3, 13, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (488, 0, '2022-10-05 12:50:00', 1, 3, 14, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (489, 0, '2022-10-05 12:50:00', 1, 3, 15, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (490, 0, '2022-10-05 12:50:00', 1, 3, 16, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (491, 0, '2022-10-05 12:50:00', 1, 3, 17, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (492, 0, '2022-10-05 12:50:00', 1, 3, 18, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (493, 0, '2022-10-05 12:50:00', 1, 3, 19, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (494, 0, '2022-10-05 12:50:00', 1, 3, 20, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (495, 0, '2022-10-05 12:50:00', 1, 3, 21, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (496, 0, '2022-10-05 12:50:00', 1, 3, 22, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (497, 0, '2022-10-05 12:50:00', 1, 3, 23, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (498, 0, '2022-10-05 12:50:00', 1, 3, 24, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (499, 0, '2022-10-05 12:50:00', 1, 3, 25, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (500, 0, '2022-10-05 12:50:00', 1, 3, 26, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (501, 0, '2022-10-05 12:50:00', 1, 3, 27, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (502, 0, '2022-10-05 12:50:00', 1, 3, 28, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (503, 0, '2022-10-05 12:50:00', 1, 3, 29, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (504, 0, '2022-10-05 12:50:00', 1, 3, 30, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (505, 0, '2022-10-05 12:50:00', 1, 3, 31, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (506, 0, '2022-10-05 12:50:00', 1, 3, 32, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (507, 0, '2022-10-05 12:50:00', 1, 3, 33, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (508, 0, '2022-10-05 12:50:00', 1, 3, 34, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (509, 0, '2022-10-05 12:50:00', 1, 3, 35, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (510, 0, '2022-10-05 12:50:00', 1, 3, 36, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (511, 0, '2022-10-05 12:50:00', 1, 3, 37, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (512, 0, '2022-10-05 12:50:00', 1, 3, 38, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (513, 0, '2022-10-05 12:50:00', 1, 3, 39, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (514, 0, '2022-10-05 12:50:00', 1, 3, 40, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (515, 0, '2022-10-05 12:50:00', 1, 3, 41, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (516, 0, '2022-10-05 12:50:00', 1, 3, 42, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (517, 0, '2022-10-05 12:55:00', 1, 1, 0, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (518, 0, '2022-10-05 12:55:00', 1, 1, 1, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (519, 0, '2022-10-05 12:55:00', 1, 1, 2, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (520, 0, '2022-10-05 12:55:00', 1, 1, 3, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (521, 0, '2022-10-05 12:55:00', 1, 1, 4, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (522, 0, '2022-10-05 12:55:00', 1, 1, 5, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (523, 0, '2022-10-05 12:55:00', 1, 1, 6, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (524, 0, '2022-10-05 12:55:00', 1, 1, 7, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (525, 0, '2022-10-05 12:55:00', 1, 1, 8, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (526, 0, '2022-10-05 12:55:00', 1, 1, 9, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (527, 0, '2022-10-05 12:55:00', 1, 1, 10, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (528, 0, '2022-10-05 12:55:00', 1, 1, 11, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (529, 0, '2022-10-05 12:55:00', 1, 1, 12, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (530, 0, '2022-10-05 12:55:00', 1, 1, 13, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (531, 0, '2022-10-05 12:55:00', 1, 1, 14, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (532, 0, '2022-10-05 12:55:00', 1, 1, 15, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (533, 0, '2022-10-05 12:55:00', 1, 1, 16, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (534, 0, '2022-10-05 12:55:00', 1, 1, 17, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (535, 0, '2022-10-05 12:55:00', 1, 1, 18, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (536, 0, '2022-10-05 12:55:00', 1, 1, 19, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (537, 0, '2022-10-05 12:55:00', 1, 1, 20, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (538, 0, '2022-10-05 12:55:00', 1, 1, 21, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (539, 0, '2022-10-05 12:55:00', 1, 1, 22, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (540, 0, '2022-10-05 12:55:00', 1, 1, 23, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (541, 0, '2022-10-05 12:55:00', 1, 1, 24, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (542, 0, '2022-10-05 12:55:00', 1, 1, 25, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (543, 0, '2022-10-05 12:55:00', 1, 1, 26, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (544, 0, '2022-10-05 12:55:00', 1, 1, 27, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (545, 0, '2022-10-05 12:55:00', 1, 1, 28, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (546, 0, '2022-10-05 12:55:00', 1, 1, 29, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (547, 0, '2022-10-05 12:55:00', 1, 1, 30, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (548, 0, '2022-10-05 12:55:00', 1, 1, 31, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (549, 0, '2022-10-05 12:55:00', 1, 1, 32, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (550, 0, '2022-10-05 12:55:00', 1, 1, 33, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (551, 0, '2022-10-05 12:55:00', 1, 1, 34, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (552, 0, '2022-10-05 12:55:00', 1, 1, 35, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (553, 0, '2022-10-05 12:55:00', 1, 1, 36, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (554, 0, '2022-10-05 12:55:00', 1, 1, 37, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (555, 0, '2022-10-05 12:55:00', 1, 1, 38, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (556, 0, '2022-10-05 12:55:00', 1, 1, 39, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (557, 0, '2022-10-05 12:55:00', 1, 1, 40, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (558, 0, '2022-10-05 12:55:00', 1, 1, 41, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (559, 0, '2022-10-05 12:55:00', 1, 1, 42, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (560, 0, '2022-10-05 12:55:00', 1, 2, 0, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (561, 0, '2022-10-05 12:55:00', 1, 2, 1, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (562, 0, '2022-10-05 12:55:00', 1, 2, 2, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (563, 0, '2022-10-05 12:55:00', 1, 2, 3, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (564, 0, '2022-10-05 12:55:00', 1, 2, 4, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (565, 0, '2022-10-05 12:55:00', 1, 2, 5, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (566, 0, '2022-10-05 12:55:00', 1, 2, 6, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (567, 0, '2022-10-05 12:55:00', 1, 2, 7, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (568, 0, '2022-10-05 12:55:00', 1, 2, 8, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (569, 0, '2022-10-05 12:55:00', 1, 2, 9, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (570, 0, '2022-10-05 12:55:00', 1, 2, 10, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (571, 0, '2022-10-05 12:55:00', 1, 2, 11, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (572, 0, '2022-10-05 12:55:00', 1, 2, 12, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (573, 0, '2022-10-05 12:55:00', 1, 2, 13, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (574, 0, '2022-10-05 12:55:00', 1, 2, 14, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (575, 0, '2022-10-05 12:55:00', 1, 2, 15, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (576, 0, '2022-10-05 12:55:00', 1, 2, 16, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (577, 0, '2022-10-05 12:55:00', 1, 2, 17, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (578, 0, '2022-10-05 12:55:00', 1, 2, 18, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (579, 0, '2022-10-05 12:55:00', 1, 2, 19, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (580, 0, '2022-10-05 12:55:00', 1, 2, 20, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (581, 0, '2022-10-05 12:55:00', 1, 2, 21, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (582, 0, '2022-10-05 12:55:00', 1, 2, 22, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (583, 0, '2022-10-05 12:55:00', 1, 2, 23, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (584, 0, '2022-10-05 12:55:00', 1, 2, 24, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (585, 0, '2022-10-05 12:55:00', 1, 2, 25, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (586, 0, '2022-10-05 12:55:00', 1, 2, 26, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (587, 0, '2022-10-05 12:55:00', 1, 2, 27, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (588, 0, '2022-10-05 12:55:00', 1, 2, 28, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (589, 0, '2022-10-05 12:55:00', 1, 2, 29, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (590, 0, '2022-10-05 12:55:00', 1, 2, 30, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (591, 0, '2022-10-05 12:55:00', 1, 2, 31, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (592, 0, '2022-10-05 12:55:00', 1, 2, 32, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (593, 0, '2022-10-05 12:55:00', 1, 2, 33, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (594, 0, '2022-10-05 12:55:00', 1, 2, 34, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (595, 0, '2022-10-05 12:55:00', 1, 2, 35, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (596, 0, '2022-10-05 12:55:00', 1, 2, 36, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (597, 0, '2022-10-05 12:55:00', 1, 2, 37, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (598, 0, '2022-10-05 12:55:00', 1, 2, 38, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (599, 0, '2022-10-05 12:55:00', 1, 2, 39, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (600, 0, '2022-10-05 12:55:00', 1, 2, 40, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (601, 0, '2022-10-05 12:55:00', 1, 2, 41, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (602, 0, '2022-10-05 12:55:00', 1, 2, 42, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (603, 0, '2022-10-05 12:55:00', 1, 3, 0, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (604, 0, '2022-10-05 12:55:00', 1, 3, 1, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (605, 0, '2022-10-05 12:55:00', 1, 3, 2, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (606, 0, '2022-10-05 12:55:00', 1, 3, 3, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (607, 0, '2022-10-05 12:55:00', 1, 3, 4, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (608, 0, '2022-10-05 12:55:00', 1, 3, 5, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (609, 0, '2022-10-05 12:55:00', 1, 3, 6, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (610, 0, '2022-10-05 12:55:00', 1, 3, 7, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (611, 0, '2022-10-05 12:55:00', 1, 3, 8, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (612, 0, '2022-10-05 12:55:00', 1, 3, 9, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (613, 0, '2022-10-05 12:55:00', 1, 3, 10, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (614, 0, '2022-10-05 12:55:00', 1, 3, 11, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (615, 0, '2022-10-05 12:55:00', 1, 3, 12, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (616, 0, '2022-10-05 12:55:00', 1, 3, 13, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (617, 0, '2022-10-05 12:55:00', 1, 3, 14, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (618, 0, '2022-10-05 12:55:00', 1, 3, 15, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (619, 0, '2022-10-05 12:55:00', 1, 3, 16, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (620, 0, '2022-10-05 12:55:00', 1, 3, 17, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (621, 0, '2022-10-05 12:55:00', 1, 3, 18, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (622, 0, '2022-10-05 12:55:00', 1, 3, 19, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (623, 0, '2022-10-05 12:55:00', 1, 3, 20, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (624, 0, '2022-10-05 12:55:00', 1, 3, 21, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (625, 0, '2022-10-05 12:55:00', 1, 3, 22, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (626, 0, '2022-10-05 12:55:00', 1, 3, 23, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (627, 0, '2022-10-05 12:55:00', 1, 3, 24, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (628, 0, '2022-10-05 12:55:00', 1, 3, 25, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (629, 0, '2022-10-05 12:55:00', 1, 3, 26, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (630, 0, '2022-10-05 12:55:00', 1, 3, 27, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (631, 0, '2022-10-05 12:55:00', 1, 3, 28, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (632, 0, '2022-10-05 12:55:00', 1, 3, 29, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (633, 0, '2022-10-05 12:55:00', 1, 3, 30, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (634, 0, '2022-10-05 12:55:00', 1, 3, 31, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (635, 0, '2022-10-05 12:55:00', 1, 3, 32, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (636, 0, '2022-10-05 12:55:00', 1, 3, 33, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (637, 0, '2022-10-05 12:55:00', 1, 3, 34, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (638, 0, '2022-10-05 12:55:00', 1, 3, 35, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (639, 0, '2022-10-05 12:55:00', 1, 3, 36, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (640, 0, '2022-10-05 12:55:00', 1, 3, 37, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (641, 0, '2022-10-05 12:55:00', 1, 3, 38, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (642, 0, '2022-10-05 12:55:00', 1, 3, 39, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (643, 0, '2022-10-05 12:55:00', 1, 3, 40, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (644, 0, '2022-10-05 12:55:00', 1, 3, 41, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (645, 0, '2022-10-05 12:55:00', 1, 3, 42, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (646, 0, '2022-10-05 13:00:00', 1, 1, 0, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (647, 0, '2022-10-05 13:00:00', 1, 1, 1, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (648, 0, '2022-10-05 13:00:00', 1, 1, 2, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (649, 0, '2022-10-05 13:00:00', 1, 1, 3, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (650, 0, '2022-10-05 13:00:00', 1, 1, 4, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (651, 0, '2022-10-05 13:00:00', 1, 1, 5, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (652, 0, '2022-10-05 13:00:00', 1, 1, 6, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (653, 0, '2022-10-05 13:00:00', 1, 1, 7, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (654, 0, '2022-10-05 13:00:00', 1, 1, 8, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (655, 0, '2022-10-05 13:00:00', 1, 1, 9, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (656, 0, '2022-10-05 13:00:00', 1, 1, 10, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (657, 0, '2022-10-05 13:00:00', 1, 1, 11, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (658, 0, '2022-10-05 13:00:00', 1, 1, 12, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (659, 0, '2022-10-05 13:00:00', 1, 1, 13, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (660, 0, '2022-10-05 13:00:00', 1, 1, 14, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (661, 0, '2022-10-05 13:00:00', 1, 1, 15, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (662, 0, '2022-10-05 13:00:00', 1, 1, 16, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (663, 0, '2022-10-05 13:00:00', 1, 1, 17, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (664, 0, '2022-10-05 13:00:00', 1, 1, 18, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (665, 0, '2022-10-05 13:00:00', 1, 1, 19, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (666, 0, '2022-10-05 13:00:00', 1, 1, 20, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (667, 0, '2022-10-05 13:00:00', 1, 1, 21, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (668, 0, '2022-10-05 13:00:00', 1, 1, 22, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (669, 0, '2022-10-05 13:00:00', 1, 1, 23, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (670, 0, '2022-10-05 13:00:00', 1, 1, 24, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (671, 0, '2022-10-05 13:00:00', 1, 1, 25, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (672, 0, '2022-10-05 13:00:00', 1, 1, 26, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (673, 0, '2022-10-05 13:00:00', 1, 1, 27, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (674, 0, '2022-10-05 13:00:00', 1, 1, 28, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (675, 0, '2022-10-05 13:00:00', 1, 1, 29, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (676, 0, '2022-10-05 13:00:00', 1, 1, 30, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (677, 0, '2022-10-05 13:00:00', 1, 1, 31, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (678, 0, '2022-10-05 13:00:00', 1, 1, 32, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (679, 0, '2022-10-05 13:00:00', 1, 1, 33, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (680, 0, '2022-10-05 13:00:00', 1, 1, 34, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (681, 0, '2022-10-05 13:00:00', 1, 1, 35, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (682, 0, '2022-10-05 13:00:00', 1, 1, 36, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (683, 0, '2022-10-05 13:00:00', 1, 1, 37, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (684, 0, '2022-10-05 13:00:00', 1, 1, 38, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (685, 0, '2022-10-05 13:00:00', 1, 1, 39, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (686, 0, '2022-10-05 13:00:00', 1, 1, 40, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (687, 0, '2022-10-05 13:00:00', 1, 1, 41, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (688, 0, '2022-10-05 13:00:00', 1, 1, 42, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (689, 0, '2022-10-05 13:00:00', 1, 2, 0, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (690, 0, '2022-10-05 13:00:00', 1, 2, 1, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (691, 0, '2022-10-05 13:00:00', 1, 2, 2, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (692, 0, '2022-10-05 13:00:00', 1, 2, 3, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (693, 0, '2022-10-05 13:00:00', 1, 2, 4, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (694, 0, '2022-10-05 13:00:00', 1, 2, 5, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (695, 0, '2022-10-05 13:00:00', 1, 2, 6, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (696, 0, '2022-10-05 13:00:00', 1, 2, 7, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (697, 0, '2022-10-05 13:00:00', 1, 2, 8, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (698, 0, '2022-10-05 13:00:00', 1, 2, 9, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (699, 0, '2022-10-05 13:00:00', 1, 2, 10, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (700, 0, '2022-10-05 13:00:00', 1, 2, 11, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (701, 0, '2022-10-05 13:00:00', 1, 2, 12, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (702, 0, '2022-10-05 13:00:00', 1, 2, 13, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (703, 0, '2022-10-05 13:00:00', 1, 2, 14, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (704, 0, '2022-10-05 13:00:00', 1, 2, 15, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (705, 0, '2022-10-05 13:00:00', 1, 2, 16, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (706, 0, '2022-10-05 13:00:00', 1, 2, 17, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (707, 0, '2022-10-05 13:00:00', 1, 2, 18, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (708, 0, '2022-10-05 13:00:00', 1, 2, 19, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (709, 0, '2022-10-05 13:00:00', 1, 2, 20, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (710, 0, '2022-10-05 13:00:00', 1, 2, 21, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (711, 0, '2022-10-05 13:00:00', 1, 2, 22, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (712, 0, '2022-10-05 13:00:00', 1, 2, 23, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (713, 0, '2022-10-05 13:00:00', 1, 2, 24, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (714, 0, '2022-10-05 13:00:00', 1, 2, 25, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (715, 0, '2022-10-05 13:00:00', 1, 2, 26, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (716, 0, '2022-10-05 13:00:00', 1, 2, 27, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (717, 0, '2022-10-05 13:00:00', 1, 2, 28, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (718, 0, '2022-10-05 13:00:00', 1, 2, 29, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (719, 0, '2022-10-05 13:00:00', 1, 2, 30, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (720, 0, '2022-10-05 13:00:00', 1, 2, 31, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (721, 0, '2022-10-05 13:00:00', 1, 2, 32, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (722, 0, '2022-10-05 13:00:00', 1, 2, 33, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (723, 0, '2022-10-05 13:00:00', 1, 2, 34, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (724, 0, '2022-10-05 13:00:00', 1, 2, 35, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (725, 0, '2022-10-05 13:00:00', 1, 2, 36, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (726, 0, '2022-10-05 13:00:00', 1, 2, 37, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (727, 0, '2022-10-05 13:00:00', 1, 2, 38, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (728, 0, '2022-10-05 13:00:00', 1, 2, 39, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (729, 0, '2022-10-05 13:00:00', 1, 2, 40, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (730, 0, '2022-10-05 13:00:00', 1, 2, 41, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (731, 0, '2022-10-05 13:00:00', 1, 2, 42, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (732, 0, '2022-10-05 13:00:00', 1, 3, 0, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (733, 0, '2022-10-05 13:00:00', 1, 3, 1, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (734, 0, '2022-10-05 13:00:00', 1, 3, 2, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (735, 0, '2022-10-05 13:00:00', 1, 3, 3, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (736, 0, '2022-10-05 13:00:00', 1, 3, 4, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (737, 0, '2022-10-05 13:00:00', 1, 3, 5, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (738, 0, '2022-10-05 13:00:00', 1, 3, 6, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (739, 0, '2022-10-05 13:00:00', 1, 3, 7, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (740, 0, '2022-10-05 13:00:00', 1, 3, 8, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (741, 0, '2022-10-05 13:00:00', 1, 3, 9, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (742, 0, '2022-10-05 13:00:00', 1, 3, 10, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (743, 0, '2022-10-05 13:00:00', 1, 3, 11, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (744, 0, '2022-10-05 13:00:00', 1, 3, 12, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (745, 0, '2022-10-05 13:00:00', 1, 3, 13, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (746, 0, '2022-10-05 13:00:00', 1, 3, 14, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (747, 0, '2022-10-05 13:00:00', 1, 3, 15, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (748, 0, '2022-10-05 13:00:00', 1, 3, 16, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (749, 0, '2022-10-05 13:00:00', 1, 3, 17, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (750, 0, '2022-10-05 13:00:00', 1, 3, 18, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (751, 0, '2022-10-05 13:00:00', 1, 3, 19, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (752, 0, '2022-10-05 13:00:00', 1, 3, 20, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (753, 0, '2022-10-05 13:00:00', 1, 3, 21, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (754, 0, '2022-10-05 13:00:00', 1, 3, 22, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (755, 0, '2022-10-05 13:00:00', 1, 3, 23, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (756, 0, '2022-10-05 13:00:00', 1, 3, 24, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (757, 0, '2022-10-05 13:00:00', 1, 3, 25, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (758, 0, '2022-10-05 13:00:00', 1, 3, 26, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (759, 0, '2022-10-05 13:00:00', 1, 3, 27, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (760, 0, '2022-10-05 13:00:00', 1, 3, 28, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (761, 0, '2022-10-05 13:00:00', 1, 3, 29, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (762, 0, '2022-10-05 13:00:00', 1, 3, 30, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (763, 0, '2022-10-05 13:00:00', 1, 3, 31, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (764, 0, '2022-10-05 13:00:00', 1, 3, 32, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (765, 0, '2022-10-05 13:00:00', 1, 3, 33, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (766, 0, '2022-10-05 13:00:00', 1, 3, 34, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (767, 0, '2022-10-05 13:00:00', 1, 3, 35, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (768, 0, '2022-10-05 13:00:00', 1, 3, 36, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (769, 0, '2022-10-05 13:00:00', 1, 3, 37, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (770, 0, '2022-10-05 13:00:00', 1, 3, 38, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (771, 0, '2022-10-05 13:00:00', 1, 3, 39, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (772, 0, '2022-10-05 13:00:00', 1, 3, 40, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (773, 0, '2022-10-05 13:00:00', 1, 3, 41, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (774, 0, '2022-10-05 13:00:00', 1, 3, 42, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (775, 0, '2022-10-05 13:05:00', 1, 1, 0, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (776, 0, '2022-10-05 13:05:00', 1, 1, 1, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (777, 0, '2022-10-05 13:05:00', 1, 1, 2, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (778, 0, '2022-10-05 13:05:00', 1, 1, 3, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (779, 0, '2022-10-05 13:05:00', 1, 1, 4, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (780, 0, '2022-10-05 13:05:00', 1, 1, 5, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (781, 0, '2022-10-05 13:05:00', 1, 1, 6, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (782, 0, '2022-10-05 13:05:00', 1, 1, 7, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (783, 0, '2022-10-05 13:05:00', 1, 1, 8, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (784, 0, '2022-10-05 13:05:00', 1, 1, 9, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (785, 0, '2022-10-05 13:05:00', 1, 1, 10, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (786, 0, '2022-10-05 13:05:00', 1, 1, 11, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (787, 0, '2022-10-05 13:05:00', 1, 1, 12, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (788, 0, '2022-10-05 13:05:00', 1, 1, 13, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (789, 0, '2022-10-05 13:05:00', 1, 1, 14, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (790, 0, '2022-10-05 13:05:00', 1, 1, 15, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (791, 0, '2022-10-05 13:05:00', 1, 1, 16, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (792, 0, '2022-10-05 13:05:00', 1, 1, 17, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (793, 0, '2022-10-05 13:05:00', 1, 1, 18, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (794, 0, '2022-10-05 13:05:00', 1, 1, 19, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (795, 0, '2022-10-05 13:05:00', 1, 1, 20, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (796, 0, '2022-10-05 13:05:00', 1, 1, 21, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (797, 0, '2022-10-05 13:05:00', 1, 1, 22, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (798, 0, '2022-10-05 13:05:00', 1, 1, 23, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (799, 0, '2022-10-05 13:05:00', 1, 1, 24, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (800, 0, '2022-10-05 13:05:00', 1, 1, 25, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (801, 0, '2022-10-05 13:05:00', 1, 1, 26, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (802, 0, '2022-10-05 13:05:00', 1, 1, 27, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (803, 0, '2022-10-05 13:05:00', 1, 1, 28, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (804, 0, '2022-10-05 13:05:00', 1, 1, 29, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (805, 0, '2022-10-05 13:05:00', 1, 1, 30, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (806, 0, '2022-10-05 13:05:00', 1, 1, 31, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (807, 0, '2022-10-05 13:05:00', 1, 1, 32, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (808, 0, '2022-10-05 13:05:00', 1, 1, 33, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (809, 0, '2022-10-05 13:05:00', 1, 1, 34, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (810, 0, '2022-10-05 13:05:00', 1, 1, 35, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (811, 0, '2022-10-05 13:05:00', 1, 1, 36, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (812, 0, '2022-10-05 13:05:00', 1, 1, 37, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (813, 0, '2022-10-05 13:05:00', 1, 1, 38, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (814, 0, '2022-10-05 13:05:00', 1, 1, 39, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (815, 0, '2022-10-05 13:05:00', 1, 1, 40, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (816, 0, '2022-10-05 13:05:00', 1, 1, 41, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (817, 0, '2022-10-05 13:05:00', 1, 1, 42, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (818, 0, '2022-10-05 13:05:00', 1, 2, 0, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (819, 0, '2022-10-05 13:05:00', 1, 2, 1, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (820, 0, '2022-10-05 13:05:00', 1, 2, 2, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (821, 0, '2022-10-05 13:05:00', 1, 2, 3, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (822, 0, '2022-10-05 13:05:00', 1, 2, 4, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (823, 0, '2022-10-05 13:05:00', 1, 2, 5, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (824, 0, '2022-10-05 13:05:00', 1, 2, 6, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (825, 0, '2022-10-05 13:05:00', 1, 2, 7, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (826, 0, '2022-10-05 13:05:00', 1, 2, 8, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (827, 0, '2022-10-05 13:05:00', 1, 2, 9, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (828, 0, '2022-10-05 13:05:00', 1, 2, 10, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (829, 0, '2022-10-05 13:05:00', 1, 2, 11, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (830, 0, '2022-10-05 13:05:00', 1, 2, 12, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (831, 0, '2022-10-05 13:05:00', 1, 2, 13, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (832, 0, '2022-10-05 13:05:00', 1, 2, 14, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (833, 0, '2022-10-05 13:05:00', 1, 2, 15, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (834, 0, '2022-10-05 13:05:00', 1, 2, 16, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (835, 0, '2022-10-05 13:05:00', 1, 2, 17, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (836, 0, '2022-10-05 13:05:00', 1, 2, 18, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (837, 0, '2022-10-05 13:05:00', 1, 2, 19, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (838, 0, '2022-10-05 13:05:00', 1, 2, 20, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (839, 0, '2022-10-05 13:05:00', 1, 2, 21, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (840, 0, '2022-10-05 13:05:00', 1, 2, 22, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (841, 0, '2022-10-05 13:05:00', 1, 2, 23, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (842, 0, '2022-10-05 13:05:00', 1, 2, 24, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (843, 0, '2022-10-05 13:05:00', 1, 2, 25, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (844, 0, '2022-10-05 13:05:00', 1, 2, 26, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (845, 0, '2022-10-05 13:05:00', 1, 2, 27, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (846, 0, '2022-10-05 13:05:00', 1, 2, 28, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (847, 0, '2022-10-05 13:05:00', 1, 2, 29, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (848, 0, '2022-10-05 13:05:00', 1, 2, 30, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (849, 0, '2022-10-05 13:05:00', 1, 2, 31, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (850, 0, '2022-10-05 13:05:00', 1, 2, 32, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (851, 0, '2022-10-05 13:05:00', 1, 2, 33, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (852, 0, '2022-10-05 13:05:00', 1, 2, 34, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (853, 0, '2022-10-05 13:05:00', 1, 2, 35, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (854, 0, '2022-10-05 13:05:00', 1, 2, 36, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (855, 0, '2022-10-05 13:05:00', 1, 2, 37, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (856, 0, '2022-10-05 13:05:00', 1, 2, 38, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (857, 0, '2022-10-05 13:05:00', 1, 2, 39, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (858, 0, '2022-10-05 13:05:00', 1, 2, 40, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (859, 0, '2022-10-05 13:05:00', 1, 2, 41, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (860, 0, '2022-10-05 13:05:00', 1, 2, 42, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (861, 0, '2022-10-05 13:05:00', 1, 3, 0, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (862, 0, '2022-10-05 13:05:00', 1, 3, 1, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (863, 0, '2022-10-05 13:05:00', 1, 3, 2, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (864, 0, '2022-10-05 13:05:00', 1, 3, 3, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (865, 0, '2022-10-05 13:05:00', 1, 3, 4, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (866, 0, '2022-10-05 13:05:00', 1, 3, 5, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (867, 0, '2022-10-05 13:05:00', 1, 3, 6, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (868, 0, '2022-10-05 13:05:00', 1, 3, 7, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (869, 0, '2022-10-05 13:05:00', 1, 3, 8, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (870, 0, '2022-10-05 13:05:00', 1, 3, 9, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (871, 0, '2022-10-05 13:05:00', 1, 3, 10, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (872, 0, '2022-10-05 13:05:00', 1, 3, 11, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (873, 0, '2022-10-05 13:05:00', 1, 3, 12, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (874, 0, '2022-10-05 13:05:00', 1, 3, 13, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (875, 0, '2022-10-05 13:05:00', 1, 3, 14, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (876, 0, '2022-10-05 13:05:00', 1, 3, 15, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (877, 0, '2022-10-05 13:05:00', 1, 3, 16, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (878, 0, '2022-10-05 13:05:00', 1, 3, 17, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (879, 0, '2022-10-05 13:05:00', 1, 3, 18, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (880, 0, '2022-10-05 13:05:00', 1, 3, 19, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (881, 0, '2022-10-05 13:05:00', 1, 3, 20, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (882, 0, '2022-10-05 13:05:00', 1, 3, 21, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (883, 0, '2022-10-05 13:05:00', 1, 3, 22, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (884, 0, '2022-10-05 13:05:00', 1, 3, 23, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (885, 0, '2022-10-05 13:05:00', 1, 3, 24, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (886, 0, '2022-10-05 13:05:00', 1, 3, 25, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (887, 0, '2022-10-05 13:05:00', 1, 3, 26, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (888, 0, '2022-10-05 13:05:00', 1, 3, 27, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (889, 0, '2022-10-05 13:05:00', 1, 3, 28, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (890, 0, '2022-10-05 13:05:00', 1, 3, 29, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (891, 0, '2022-10-05 13:05:00', 1, 3, 30, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (892, 0, '2022-10-05 13:05:00', 1, 3, 31, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (893, 0, '2022-10-05 13:05:00', 1, 3, 32, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (894, 0, '2022-10-05 13:05:00', 1, 3, 33, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (895, 0, '2022-10-05 13:05:00', 1, 3, 34, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (896, 0, '2022-10-05 13:05:00', 1, 3, 35, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (897, 0, '2022-10-05 13:05:00', 1, 3, 36, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (898, 0, '2022-10-05 13:05:00', 1, 3, 37, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (899, 0, '2022-10-05 13:05:00', 1, 3, 38, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (900, 0, '2022-10-05 13:05:00', 1, 3, 39, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (901, 0, '2022-10-05 13:05:00', 1, 3, 40, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (902, 0, '2022-10-05 13:05:00', 1, 3, 41, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (903, 0, '2022-10-05 13:05:00', 1, 3, 42, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (904, 0, '2022-10-05 13:10:00', 1, 1, 0, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (905, 0, '2022-10-05 13:10:00', 1, 1, 1, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (906, 0, '2022-10-05 13:10:00', 1, 1, 2, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (907, 0, '2022-10-05 13:10:00', 1, 1, 3, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (908, 0, '2022-10-05 13:10:00', 1, 1, 4, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (909, 0, '2022-10-05 13:10:00', 1, 1, 5, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (910, 0, '2022-10-05 13:10:00', 1, 1, 6, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (911, 0, '2022-10-05 13:10:00', 1, 1, 7, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (912, 0, '2022-10-05 13:10:00', 1, 1, 8, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (913, 0, '2022-10-05 13:10:00', 1, 1, 9, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (914, 0, '2022-10-05 13:10:00', 1, 1, 10, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (915, 0, '2022-10-05 13:10:00', 1, 1, 11, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (916, 0, '2022-10-05 13:10:00', 1, 1, 12, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (917, 0, '2022-10-05 13:10:00', 1, 1, 13, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (918, 0, '2022-10-05 13:10:00', 1, 1, 14, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (919, 0, '2022-10-05 13:10:00', 1, 1, 15, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (920, 0, '2022-10-05 13:10:00', 1, 1, 16, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (921, 0, '2022-10-05 13:10:00', 1, 1, 17, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (922, 0, '2022-10-05 13:10:00', 1, 1, 18, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (923, 0, '2022-10-05 13:10:00', 1, 1, 19, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (924, 0, '2022-10-05 13:10:00', 1, 1, 20, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (925, 0, '2022-10-05 13:10:00', 1, 1, 21, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (926, 0, '2022-10-05 13:10:00', 1, 1, 22, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (927, 0, '2022-10-05 13:10:00', 1, 1, 23, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (928, 0, '2022-10-05 13:10:00', 1, 1, 24, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (929, 0, '2022-10-05 13:10:00', 1, 1, 25, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (930, 0, '2022-10-05 13:10:00', 1, 1, 26, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (931, 0, '2022-10-05 13:10:00', 1, 1, 27, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (932, 0, '2022-10-05 13:10:00', 1, 1, 28, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (933, 0, '2022-10-05 13:10:00', 1, 1, 29, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (934, 0, '2022-10-05 13:10:00', 1, 1, 30, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (935, 0, '2022-10-05 13:10:00', 1, 1, 31, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (936, 0, '2022-10-05 13:10:00', 1, 1, 32, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (937, 0, '2022-10-05 13:10:00', 1, 1, 33, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (938, 0, '2022-10-05 13:10:00', 1, 1, 34, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (939, 0, '2022-10-05 13:10:00', 1, 1, 35, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (940, 0, '2022-10-05 13:10:00', 1, 1, 36, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (941, 0, '2022-10-05 13:10:00', 1, 1, 37, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (942, 0, '2022-10-05 13:10:00', 1, 1, 38, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (943, 0, '2022-10-05 13:10:00', 1, 1, 39, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (944, 0, '2022-10-05 13:10:00', 1, 1, 40, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (945, 0, '2022-10-05 13:10:00', 1, 1, 41, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (946, 0, '2022-10-05 13:10:00', 1, 1, 42, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (947, 0, '2022-10-05 13:10:00', 1, 2, 0, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (948, 0, '2022-10-05 13:10:00', 1, 2, 1, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (949, 0, '2022-10-05 13:10:00', 1, 2, 2, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (950, 0, '2022-10-05 13:10:00', 1, 2, 3, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (951, 0, '2022-10-05 13:10:00', 1, 2, 4, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (952, 0, '2022-10-05 13:10:00', 1, 2, 5, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (953, 0, '2022-10-05 13:10:00', 1, 2, 6, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (954, 0, '2022-10-05 13:10:00', 1, 2, 7, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (955, 0, '2022-10-05 13:10:00', 1, 2, 8, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (956, 0, '2022-10-05 13:10:00', 1, 2, 9, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (957, 0, '2022-10-05 13:10:00', 1, 2, 10, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (958, 0, '2022-10-05 13:10:00', 1, 2, 11, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (959, 0, '2022-10-05 13:10:00', 1, 2, 12, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (960, 0, '2022-10-05 13:10:00', 1, 2, 13, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (961, 0, '2022-10-05 13:10:00', 1, 2, 14, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (962, 0, '2022-10-05 13:10:00', 1, 2, 15, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (963, 0, '2022-10-05 13:10:00', 1, 2, 16, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (964, 0, '2022-10-05 13:10:00', 1, 2, 17, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (965, 0, '2022-10-05 13:10:00', 1, 2, 18, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (966, 0, '2022-10-05 13:10:00', 1, 2, 19, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (967, 0, '2022-10-05 13:10:00', 1, 2, 20, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (968, 0, '2022-10-05 13:10:00', 1, 2, 21, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (969, 0, '2022-10-05 13:10:00', 1, 2, 22, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (970, 0, '2022-10-05 13:10:00', 1, 2, 23, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (971, 0, '2022-10-05 13:10:00', 1, 2, 24, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (972, 0, '2022-10-05 13:10:00', 1, 2, 25, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (973, 0, '2022-10-05 13:10:00', 1, 2, 26, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (974, 0, '2022-10-05 13:10:00', 1, 2, 27, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (975, 0, '2022-10-05 13:10:00', 1, 2, 28, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (976, 0, '2022-10-05 13:10:00', 1, 2, 29, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (977, 0, '2022-10-05 13:10:00', 1, 2, 30, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (978, 0, '2022-10-05 13:10:00', 1, 2, 31, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (979, 0, '2022-10-05 13:10:00', 1, 2, 32, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (980, 0, '2022-10-05 13:10:00', 1, 2, 33, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (981, 0, '2022-10-05 13:10:00', 1, 2, 34, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (982, 0, '2022-10-05 13:10:00', 1, 2, 35, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (983, 0, '2022-10-05 13:10:00', 1, 2, 36, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (984, 0, '2022-10-05 13:10:00', 1, 2, 37, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (985, 0, '2022-10-05 13:10:00', 1, 2, 38, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (986, 0, '2022-10-05 13:10:00', 1, 2, 39, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (987, 0, '2022-10-05 13:10:00', 1, 2, 40, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (988, 0, '2022-10-05 13:10:00', 1, 2, 41, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (989, 0, '2022-10-05 13:10:00', 1, 2, 42, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (990, 0, '2022-10-05 13:10:00', 1, 3, 0, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (991, 0, '2022-10-05 13:10:00', 1, 3, 1, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (992, 0, '2022-10-05 13:10:00', 1, 3, 2, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (993, 0, '2022-10-05 13:10:00', 1, 3, 3, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (994, 0, '2022-10-05 13:10:00', 1, 3, 4, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (995, 0, '2022-10-05 13:10:00', 1, 3, 5, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (996, 0, '2022-10-05 13:10:00', 1, 3, 6, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (997, 0, '2022-10-05 13:10:00', 1, 3, 7, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (998, 0, '2022-10-05 13:10:00', 1, 3, 8, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (999, 0, '2022-10-05 13:10:00', 1, 3, 9, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1000, 0, '2022-10-05 13:10:00', 1, 3, 10, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1001, 0, '2022-10-05 13:10:00', 1, 3, 11, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1002, 0, '2022-10-05 13:10:00', 1, 3, 12, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1003, 0, '2022-10-05 13:10:00', 1, 3, 13, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1004, 0, '2022-10-05 13:10:00', 1, 3, 14, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1005, 0, '2022-10-05 13:10:00', 1, 3, 15, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1006, 0, '2022-10-05 13:10:00', 1, 3, 16, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1007, 0, '2022-10-05 13:10:00', 1, 3, 17, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1008, 0, '2022-10-05 13:10:00', 1, 3, 18, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1009, 0, '2022-10-05 13:10:00', 1, 3, 19, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1010, 0, '2022-10-05 13:10:00', 1, 3, 20, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1011, 0, '2022-10-05 13:10:00', 1, 3, 21, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1012, 0, '2022-10-05 13:10:00', 1, 3, 22, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1013, 0, '2022-10-05 13:10:00', 1, 3, 23, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1014, 0, '2022-10-05 13:10:00', 1, 3, 24, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1015, 0, '2022-10-05 13:10:00', 1, 3, 25, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1016, 0, '2022-10-05 13:10:00', 1, 3, 26, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1017, 0, '2022-10-05 13:10:00', 1, 3, 27, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1018, 0, '2022-10-05 13:10:00', 1, 3, 28, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1019, 0, '2022-10-05 13:10:00', 1, 3, 29, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1020, 0, '2022-10-05 13:10:00', 1, 3, 30, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1021, 0, '2022-10-05 13:10:00', 1, 3, 31, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1022, 0, '2022-10-05 13:10:00', 1, 3, 32, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1023, 0, '2022-10-05 13:10:00', 1, 3, 33, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1024, 0, '2022-10-05 13:10:00', 1, 3, 34, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1025, 0, '2022-10-05 13:10:00', 1, 3, 35, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1026, 0, '2022-10-05 13:10:00', 1, 3, 36, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1027, 0, '2022-10-05 13:10:00', 1, 3, 37, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1028, 0, '2022-10-05 13:10:00', 1, 3, 38, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1029, 0, '2022-10-05 13:10:00', 1, 3, 39, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1030, 0, '2022-10-05 13:10:00', 1, 3, 40, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1031, 0, '2022-10-05 13:10:00', 1, 3, 41, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1032, 0, '2022-10-05 13:10:00', 1, 3, 42, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1033, 0, '2022-10-05 13:15:00', 1, 1, 0, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1034, 0, '2022-10-05 13:15:00', 1, 1, 1, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1035, 0, '2022-10-05 13:15:00', 1, 1, 2, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1036, 0, '2022-10-05 13:15:00', 1, 1, 3, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1037, 0, '2022-10-05 13:15:00', 1, 1, 4, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1038, 0, '2022-10-05 13:15:00', 1, 1, 5, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1039, 0, '2022-10-05 13:15:00', 1, 1, 6, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1040, 0, '2022-10-05 13:15:00', 1, 1, 7, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1041, 0, '2022-10-05 13:15:00', 1, 1, 8, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1042, 0, '2022-10-05 13:15:00', 1, 1, 9, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1043, 0, '2022-10-05 13:15:00', 1, 1, 10, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1044, 0, '2022-10-05 13:15:00', 1, 1, 11, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1045, 0, '2022-10-05 13:15:00', 1, 1, 12, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1046, 0, '2022-10-05 13:15:00', 1, 1, 13, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1047, 0, '2022-10-05 13:15:00', 1, 1, 14, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1048, 0, '2022-10-05 13:15:00', 1, 1, 15, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1049, 0, '2022-10-05 13:15:00', 1, 1, 16, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1050, 0, '2022-10-05 13:15:00', 1, 1, 17, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1051, 0, '2022-10-05 13:15:00', 1, 1, 18, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1052, 0, '2022-10-05 13:15:00', 1, 1, 19, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1053, 0, '2022-10-05 13:15:00', 1, 1, 20, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1054, 0, '2022-10-05 13:15:00', 1, 1, 21, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1055, 0, '2022-10-05 13:15:00', 1, 1, 22, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1056, 0, '2022-10-05 13:15:00', 1, 1, 23, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1057, 0, '2022-10-05 13:15:00', 1, 1, 24, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1058, 0, '2022-10-05 13:15:00', 1, 1, 25, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1059, 0, '2022-10-05 13:15:00', 1, 1, 26, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1060, 0, '2022-10-05 13:15:00', 1, 1, 27, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1061, 0, '2022-10-05 13:15:00', 1, 1, 28, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1062, 0, '2022-10-05 13:15:00', 1, 1, 29, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1063, 0, '2022-10-05 13:15:00', 1, 1, 30, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1064, 0, '2022-10-05 13:15:00', 1, 1, 31, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1065, 0, '2022-10-05 13:15:00', 1, 1, 32, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1066, 0, '2022-10-05 13:15:00', 1, 1, 33, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1067, 0, '2022-10-05 13:15:00', 1, 1, 34, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1068, 0, '2022-10-05 13:15:00', 1, 1, 35, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1069, 0, '2022-10-05 13:15:00', 1, 1, 36, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1070, 0, '2022-10-05 13:15:00', 1, 1, 37, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1071, 0, '2022-10-05 13:15:00', 1, 1, 38, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1072, 0, '2022-10-05 13:15:00', 1, 1, 39, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1073, 0, '2022-10-05 13:15:00', 1, 1, 40, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1074, 0, '2022-10-05 13:15:00', 1, 1, 41, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1075, 0, '2022-10-05 13:15:00', 1, 1, 42, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1076, 0, '2022-10-05 13:15:00', 1, 2, 0, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1077, 0, '2022-10-05 13:15:00', 1, 2, 1, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1078, 0, '2022-10-05 13:15:00', 1, 2, 2, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1079, 0, '2022-10-05 13:15:00', 1, 2, 3, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1080, 0, '2022-10-05 13:15:00', 1, 2, 4, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1081, 0, '2022-10-05 13:15:00', 1, 2, 5, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1082, 0, '2022-10-05 13:15:00', 1, 2, 6, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1083, 0, '2022-10-05 13:15:00', 1, 2, 7, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1084, 0, '2022-10-05 13:15:00', 1, 2, 8, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1085, 0, '2022-10-05 13:15:00', 1, 2, 9, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1086, 0, '2022-10-05 13:15:00', 1, 2, 10, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1087, 0, '2022-10-05 13:15:00', 1, 2, 11, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1088, 0, '2022-10-05 13:15:00', 1, 2, 12, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1089, 0, '2022-10-05 13:15:00', 1, 2, 13, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1090, 0, '2022-10-05 13:15:00', 1, 2, 14, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1091, 0, '2022-10-05 13:15:00', 1, 2, 15, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1092, 0, '2022-10-05 13:15:00', 1, 2, 16, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1093, 0, '2022-10-05 13:15:00', 1, 2, 17, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1094, 0, '2022-10-05 13:15:00', 1, 2, 18, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1095, 0, '2022-10-05 13:15:00', 1, 2, 19, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1096, 0, '2022-10-05 13:15:00', 1, 2, 20, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1097, 0, '2022-10-05 13:15:00', 1, 2, 21, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1098, 0, '2022-10-05 13:15:00', 1, 2, 22, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1099, 0, '2022-10-05 13:15:00', 1, 2, 23, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1100, 0, '2022-10-05 13:15:00', 1, 2, 24, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1101, 0, '2022-10-05 13:15:00', 1, 2, 25, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1102, 0, '2022-10-05 13:15:00', 1, 2, 26, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1103, 0, '2022-10-05 13:15:00', 1, 2, 27, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1104, 0, '2022-10-05 13:15:00', 1, 2, 28, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1105, 0, '2022-10-05 13:15:00', 1, 2, 29, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1106, 0, '2022-10-05 13:15:00', 1, 2, 30, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1107, 0, '2022-10-05 13:15:00', 1, 2, 31, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1108, 0, '2022-10-05 13:15:00', 1, 2, 32, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1109, 0, '2022-10-05 13:15:00', 1, 2, 33, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1110, 0, '2022-10-05 13:15:00', 1, 2, 34, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1111, 0, '2022-10-05 13:15:00', 1, 2, 35, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1112, 0, '2022-10-05 13:15:00', 1, 2, 36, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1113, 0, '2022-10-05 13:15:00', 1, 2, 37, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1114, 0, '2022-10-05 13:15:00', 1, 2, 38, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1115, 0, '2022-10-05 13:15:00', 1, 2, 39, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1116, 0, '2022-10-05 13:15:00', 1, 2, 40, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1117, 0, '2022-10-05 13:15:00', 1, 2, 41, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1118, 0, '2022-10-05 13:15:00', 1, 2, 42, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1119, 0, '2022-10-05 13:15:00', 1, 3, 0, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1120, 0, '2022-10-05 13:15:00', 1, 3, 1, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1121, 0, '2022-10-05 13:15:00', 1, 3, 2, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1122, 0, '2022-10-05 13:15:00', 1, 3, 3, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1123, 0, '2022-10-05 13:15:00', 1, 3, 4, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1124, 0, '2022-10-05 13:15:00', 1, 3, 5, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1125, 0, '2022-10-05 13:15:00', 1, 3, 6, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1126, 0, '2022-10-05 13:15:00', 1, 3, 7, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1127, 0, '2022-10-05 13:15:00', 1, 3, 8, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1128, 0, '2022-10-05 13:15:00', 1, 3, 9, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1129, 0, '2022-10-05 13:15:00', 1, 3, 10, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1130, 0, '2022-10-05 13:15:00', 1, 3, 11, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1131, 0, '2022-10-05 13:15:00', 1, 3, 12, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1132, 0, '2022-10-05 13:15:00', 1, 3, 13, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1133, 0, '2022-10-05 13:15:00', 1, 3, 14, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1134, 0, '2022-10-05 13:15:00', 1, 3, 15, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1135, 0, '2022-10-05 13:15:00', 1, 3, 16, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1136, 0, '2022-10-05 13:15:00', 1, 3, 17, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1137, 0, '2022-10-05 13:15:00', 1, 3, 18, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1138, 0, '2022-10-05 13:15:00', 1, 3, 19, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1139, 0, '2022-10-05 13:15:00', 1, 3, 20, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1140, 0, '2022-10-05 13:15:00', 1, 3, 21, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1141, 0, '2022-10-05 13:15:00', 1, 3, 22, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1142, 0, '2022-10-05 13:15:00', 1, 3, 23, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1143, 0, '2022-10-05 13:15:00', 1, 3, 24, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1144, 0, '2022-10-05 13:15:00', 1, 3, 25, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1145, 0, '2022-10-05 13:15:00', 1, 3, 26, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1146, 0, '2022-10-05 13:15:00', 1, 3, 27, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1147, 0, '2022-10-05 13:15:00', 1, 3, 28, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1148, 0, '2022-10-05 13:15:00', 1, 3, 29, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1149, 0, '2022-10-05 13:15:00', 1, 3, 30, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1150, 0, '2022-10-05 13:15:00', 1, 3, 31, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1151, 0, '2022-10-05 13:15:00', 1, 3, 32, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1152, 0, '2022-10-05 13:15:00', 1, 3, 33, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1153, 0, '2022-10-05 13:15:00', 1, 3, 34, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1154, 0, '2022-10-05 13:15:00', 1, 3, 35, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1155, 0, '2022-10-05 13:15:00', 1, 3, 36, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1156, 0, '2022-10-05 13:15:00', 1, 3, 37, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1157, 0, '2022-10-05 13:15:00', 1, 3, 38, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1158, 0, '2022-10-05 13:15:00', 1, 3, 39, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1159, 0, '2022-10-05 13:15:00', 1, 3, 40, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1160, 0, '2022-10-05 13:15:00', 1, 3, 41, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1161, 0, '2022-10-05 13:15:00', 1, 3, 42, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1162, 0, '2022-10-05 13:20:00', 1, 1, 0, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1163, 0, '2022-10-05 13:20:00', 1, 1, 1, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1164, 0, '2022-10-05 13:20:00', 1, 1, 2, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1165, 0, '2022-10-05 13:20:00', 1, 1, 3, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1166, 0, '2022-10-05 13:20:00', 1, 1, 4, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1167, 0, '2022-10-05 13:20:00', 1, 1, 5, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1168, 0, '2022-10-05 13:20:00', 1, 1, 6, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1169, 0, '2022-10-05 13:20:00', 1, 1, 7, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1170, 0, '2022-10-05 13:20:00', 1, 1, 8, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1171, 0, '2022-10-05 13:20:00', 1, 1, 9, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1172, 0, '2022-10-05 13:20:00', 1, 1, 10, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1173, 0, '2022-10-05 13:20:00', 1, 1, 11, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1174, 0, '2022-10-05 13:20:00', 1, 1, 12, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1175, 0, '2022-10-05 13:20:00', 1, 1, 13, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1176, 0, '2022-10-05 13:20:00', 1, 1, 14, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1177, 0, '2022-10-05 13:20:00', 1, 1, 15, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1178, 0, '2022-10-05 13:20:00', 1, 1, 16, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1179, 0, '2022-10-05 13:20:00', 1, 1, 17, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1180, 0, '2022-10-05 13:20:00', 1, 1, 18, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1181, 0, '2022-10-05 13:20:00', 1, 1, 19, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1182, 0, '2022-10-05 13:20:00', 1, 1, 20, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1183, 0, '2022-10-05 13:20:00', 1, 1, 21, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1184, 0, '2022-10-05 13:20:00', 1, 1, 22, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1185, 0, '2022-10-05 13:20:00', 1, 1, 23, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1186, 0, '2022-10-05 13:20:00', 1, 1, 24, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1187, 0, '2022-10-05 13:20:00', 1, 1, 25, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1188, 0, '2022-10-05 13:20:00', 1, 1, 26, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1189, 0, '2022-10-05 13:20:00', 1, 1, 27, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1190, 0, '2022-10-05 13:20:00', 1, 1, 28, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1191, 0, '2022-10-05 13:20:00', 1, 1, 29, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1192, 0, '2022-10-05 13:20:00', 1, 1, 30, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1193, 0, '2022-10-05 13:20:00', 1, 1, 31, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1194, 0, '2022-10-05 13:20:00', 1, 1, 32, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1195, 0, '2022-10-05 13:20:00', 1, 1, 33, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1196, 0, '2022-10-05 13:20:00', 1, 1, 34, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1197, 0, '2022-10-05 13:20:00', 1, 1, 35, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1198, 0, '2022-10-05 13:20:00', 1, 1, 36, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1199, 0, '2022-10-05 13:20:00', 1, 1, 37, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1200, 0, '2022-10-05 13:20:00', 1, 1, 38, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1201, 0, '2022-10-05 13:20:00', 1, 1, 39, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1202, 0, '2022-10-05 13:20:00', 1, 1, 40, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1203, 0, '2022-10-05 13:20:00', 1, 1, 41, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1204, 0, '2022-10-05 13:20:00', 1, 1, 42, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1205, 0, '2022-10-05 13:20:00', 1, 2, 0, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1206, 0, '2022-10-05 13:20:00', 1, 2, 1, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1207, 0, '2022-10-05 13:20:00', 1, 2, 2, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1208, 0, '2022-10-05 13:20:00', 1, 2, 3, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1209, 0, '2022-10-05 13:20:00', 1, 2, 4, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1210, 0, '2022-10-05 13:20:00', 1, 2, 5, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1211, 0, '2022-10-05 13:20:00', 1, 2, 6, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1212, 0, '2022-10-05 13:20:00', 1, 2, 7, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1213, 0, '2022-10-05 13:20:00', 1, 2, 8, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1214, 0, '2022-10-05 13:20:00', 1, 2, 9, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1215, 0, '2022-10-05 13:20:00', 1, 2, 10, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1216, 0, '2022-10-05 13:20:00', 1, 2, 11, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1217, 0, '2022-10-05 13:20:00', 1, 2, 12, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1218, 0, '2022-10-05 13:20:00', 1, 2, 13, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1219, 0, '2022-10-05 13:20:00', 1, 2, 14, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1220, 0, '2022-10-05 13:20:00', 1, 2, 15, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1221, 0, '2022-10-05 13:20:00', 1, 2, 16, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1222, 0, '2022-10-05 13:20:00', 1, 2, 17, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1223, 0, '2022-10-05 13:20:00', 1, 2, 18, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1224, 0, '2022-10-05 13:20:00', 1, 2, 19, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1225, 0, '2022-10-05 13:20:00', 1, 2, 20, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1226, 0, '2022-10-05 13:20:00', 1, 2, 21, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1227, 0, '2022-10-05 13:20:00', 1, 2, 22, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1228, 0, '2022-10-05 13:20:00', 1, 2, 23, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1229, 0, '2022-10-05 13:20:00', 1, 2, 24, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1230, 0, '2022-10-05 13:20:00', 1, 2, 25, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1231, 0, '2022-10-05 13:20:00', 1, 2, 26, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1232, 0, '2022-10-05 13:20:00', 1, 2, 27, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1233, 0, '2022-10-05 13:20:00', 1, 2, 28, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1234, 0, '2022-10-05 13:20:00', 1, 2, 29, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1235, 0, '2022-10-05 13:20:00', 1, 2, 30, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1236, 0, '2022-10-05 13:20:00', 1, 2, 31, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1237, 0, '2022-10-05 13:20:00', 1, 2, 32, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1238, 0, '2022-10-05 13:20:00', 1, 2, 33, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1239, 0, '2022-10-05 13:20:00', 1, 2, 34, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1240, 0, '2022-10-05 13:20:00', 1, 2, 35, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1241, 0, '2022-10-05 13:20:00', 1, 2, 36, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1242, 0, '2022-10-05 13:20:00', 1, 2, 37, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1243, 0, '2022-10-05 13:20:00', 1, 2, 38, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1244, 0, '2022-10-05 13:20:00', 1, 2, 39, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1245, 0, '2022-10-05 13:20:00', 1, 2, 40, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1246, 0, '2022-10-05 13:20:00', 1, 2, 41, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1247, 0, '2022-10-05 13:20:00', 1, 2, 42, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1248, 0, '2022-10-05 13:20:00', 1, 3, 0, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1249, 0, '2022-10-05 13:20:00', 1, 3, 1, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1250, 0, '2022-10-05 13:20:00', 1, 3, 2, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1251, 0, '2022-10-05 13:20:00', 1, 3, 3, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1252, 0, '2022-10-05 13:20:00', 1, 3, 4, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1253, 0, '2022-10-05 13:20:00', 1, 3, 5, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1254, 0, '2022-10-05 13:20:00', 1, 3, 6, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1255, 0, '2022-10-05 13:20:00', 1, 3, 7, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1256, 0, '2022-10-05 13:20:00', 1, 3, 8, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1257, 0, '2022-10-05 13:20:00', 1, 3, 9, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1258, 0, '2022-10-05 13:20:00', 1, 3, 10, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1259, 0, '2022-10-05 13:20:00', 1, 3, 11, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1260, 0, '2022-10-05 13:20:00', 1, 3, 12, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1261, 0, '2022-10-05 13:20:00', 1, 3, 13, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1262, 0, '2022-10-05 13:20:00', 1, 3, 14, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1263, 0, '2022-10-05 13:20:00', 1, 3, 15, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1264, 0, '2022-10-05 13:20:00', 1, 3, 16, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1265, 0, '2022-10-05 13:20:00', 1, 3, 17, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1266, 0, '2022-10-05 13:20:00', 1, 3, 18, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1267, 0, '2022-10-05 13:20:00', 1, 3, 19, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1268, 0, '2022-10-05 13:20:00', 1, 3, 20, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1269, 0, '2022-10-05 13:20:00', 1, 3, 21, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1270, 0, '2022-10-05 13:20:00', 1, 3, 22, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1271, 0, '2022-10-05 13:20:00', 1, 3, 23, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1272, 0, '2022-10-05 13:20:00', 1, 3, 24, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1273, 0, '2022-10-05 13:20:00', 1, 3, 25, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1274, 0, '2022-10-05 13:20:00', 1, 3, 26, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1275, 0, '2022-10-05 13:20:00', 1, 3, 27, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1276, 0, '2022-10-05 13:20:00', 1, 3, 28, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1277, 0, '2022-10-05 13:20:00', 1, 3, 29, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1278, 0, '2022-10-05 13:20:00', 1, 3, 30, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1279, 0, '2022-10-05 13:20:00', 1, 3, 31, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1280, 0, '2022-10-05 13:20:00', 1, 3, 32, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1281, 0, '2022-10-05 13:20:00', 1, 3, 33, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1282, 0, '2022-10-05 13:20:00', 1, 3, 34, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1283, 0, '2022-10-05 13:20:00', 1, 3, 35, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1284, 0, '2022-10-05 13:20:00', 1, 3, 36, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1285, 0, '2022-10-05 13:20:00', 1, 3, 37, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1286, 0, '2022-10-05 13:20:00', 1, 3, 38, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1287, 0, '2022-10-05 13:20:00', 1, 3, 39, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1288, 0, '2022-10-05 13:20:00', 1, 3, 40, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1289, 0, '2022-10-05 13:20:00', 1, 3, 41, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1290, 0, '2022-10-05 13:20:00', 1, 3, 42, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1291, 0, '2022-10-05 13:25:00', 1, 1, 0, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1292, 0, '2022-10-05 13:25:00', 1, 1, 1, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1293, 0, '2022-10-05 13:25:00', 1, 1, 2, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1294, 0, '2022-10-05 13:25:00', 1, 1, 3, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1295, 0, '2022-10-05 13:25:00', 1, 1, 4, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1296, 0, '2022-10-05 13:25:00', 1, 1, 5, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1297, 0, '2022-10-05 13:25:00', 1, 1, 6, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1298, 0, '2022-10-05 13:25:00', 1, 1, 7, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1299, 0, '2022-10-05 13:25:00', 1, 1, 8, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1300, 0, '2022-10-05 13:25:00', 1, 1, 9, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1301, 0, '2022-10-05 13:25:00', 1, 1, 10, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1302, 0, '2022-10-05 13:25:00', 1, 1, 11, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1303, 0, '2022-10-05 13:25:00', 1, 1, 12, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1304, 0, '2022-10-05 13:25:00', 1, 1, 13, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1305, 0, '2022-10-05 13:25:00', 1, 1, 14, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1306, 0, '2022-10-05 13:25:00', 1, 1, 15, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1307, 0, '2022-10-05 13:25:00', 1, 1, 16, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1308, 0, '2022-10-05 13:25:00', 1, 1, 17, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1309, 0, '2022-10-05 13:25:00', 1, 1, 18, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1310, 0, '2022-10-05 13:25:00', 1, 1, 19, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1311, 0, '2022-10-05 13:25:00', 1, 1, 20, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1312, 0, '2022-10-05 13:25:00', 1, 1, 21, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1313, 0, '2022-10-05 13:25:00', 1, 1, 22, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1314, 0, '2022-10-05 13:25:00', 1, 1, 23, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1315, 0, '2022-10-05 13:25:00', 1, 1, 24, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1316, 0, '2022-10-05 13:25:00', 1, 1, 25, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1317, 0, '2022-10-05 13:25:00', 1, 1, 26, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1318, 0, '2022-10-05 13:25:00', 1, 1, 27, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1319, 0, '2022-10-05 13:25:00', 1, 1, 28, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1320, 0, '2022-10-05 13:25:00', 1, 1, 29, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1321, 0, '2022-10-05 13:25:00', 1, 1, 30, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1322, 0, '2022-10-05 13:25:00', 1, 1, 31, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1323, 0, '2022-10-05 13:25:00', 1, 1, 32, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1324, 0, '2022-10-05 13:25:00', 1, 1, 33, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1325, 0, '2022-10-05 13:25:00', 1, 1, 34, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1326, 0, '2022-10-05 13:25:00', 1, 1, 35, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1327, 0, '2022-10-05 13:25:00', 1, 1, 36, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1328, 0, '2022-10-05 13:25:00', 1, 1, 37, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1329, 0, '2022-10-05 13:25:00', 1, 1, 38, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1330, 0, '2022-10-05 13:25:00', 1, 1, 39, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1331, 0, '2022-10-05 13:25:00', 1, 1, 40, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1332, 0, '2022-10-05 13:25:00', 1, 1, 41, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1333, 0, '2022-10-05 13:25:00', 1, 1, 42, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1334, 0, '2022-10-05 13:25:00', 1, 2, 0, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1335, 0, '2022-10-05 13:25:00', 1, 2, 1, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1336, 0, '2022-10-05 13:25:00', 1, 2, 2, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1337, 0, '2022-10-05 13:25:00', 1, 2, 3, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1338, 0, '2022-10-05 13:25:00', 1, 2, 4, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1339, 0, '2022-10-05 13:25:00', 1, 2, 5, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1340, 0, '2022-10-05 13:25:00', 1, 2, 6, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1341, 0, '2022-10-05 13:25:00', 1, 2, 7, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1342, 0, '2022-10-05 13:25:00', 1, 2, 8, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1343, 0, '2022-10-05 13:25:00', 1, 2, 9, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1344, 0, '2022-10-05 13:25:00', 1, 2, 10, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1345, 0, '2022-10-05 13:25:00', 1, 2, 11, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1346, 0, '2022-10-05 13:25:00', 1, 2, 12, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1347, 0, '2022-10-05 13:25:00', 1, 2, 13, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1348, 0, '2022-10-05 13:25:00', 1, 2, 14, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1349, 0, '2022-10-05 13:25:00', 1, 2, 15, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1350, 0, '2022-10-05 13:25:00', 1, 2, 16, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1351, 0, '2022-10-05 13:25:00', 1, 2, 17, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1352, 0, '2022-10-05 13:25:00', 1, 2, 18, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1353, 0, '2022-10-05 13:25:00', 1, 2, 19, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1354, 0, '2022-10-05 13:25:00', 1, 2, 20, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1355, 0, '2022-10-05 13:25:00', 1, 2, 21, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1356, 0, '2022-10-05 13:25:00', 1, 2, 22, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1357, 0, '2022-10-05 13:25:00', 1, 2, 23, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1358, 0, '2022-10-05 13:25:00', 1, 2, 24, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1359, 0, '2022-10-05 13:25:00', 1, 2, 25, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1360, 0, '2022-10-05 13:25:00', 1, 2, 26, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1361, 0, '2022-10-05 13:25:00', 1, 2, 27, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1362, 0, '2022-10-05 13:25:00', 1, 2, 28, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1363, 0, '2022-10-05 13:25:00', 1, 2, 29, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1364, 0, '2022-10-05 13:25:00', 1, 2, 30, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1365, 0, '2022-10-05 13:25:00', 1, 2, 31, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1366, 0, '2022-10-05 13:25:00', 1, 2, 32, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1367, 0, '2022-10-05 13:25:00', 1, 2, 33, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1368, 0, '2022-10-05 13:25:00', 1, 2, 34, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1369, 0, '2022-10-05 13:25:00', 1, 2, 35, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1370, 0, '2022-10-05 13:25:00', 1, 2, 36, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1371, 0, '2022-10-05 13:25:00', 1, 2, 37, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1372, 0, '2022-10-05 13:25:00', 1, 2, 38, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1373, 0, '2022-10-05 13:25:00', 1, 2, 39, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1374, 0, '2022-10-05 13:25:00', 1, 2, 40, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1375, 0, '2022-10-05 13:25:00', 1, 2, 41, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1376, 0, '2022-10-05 13:25:00', 1, 2, 42, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1377, 0, '2022-10-05 13:25:00', 1, 3, 0, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1378, 0, '2022-10-05 13:25:00', 1, 3, 1, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1379, 0, '2022-10-05 13:25:00', 1, 3, 2, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1380, 0, '2022-10-05 13:25:00', 1, 3, 3, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1381, 0, '2022-10-05 13:25:00', 1, 3, 4, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1382, 0, '2022-10-05 13:25:00', 1, 3, 5, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1383, 0, '2022-10-05 13:25:00', 1, 3, 6, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1384, 0, '2022-10-05 13:25:00', 1, 3, 7, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1385, 0, '2022-10-05 13:25:00', 1, 3, 8, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1386, 0, '2022-10-05 13:25:00', 1, 3, 9, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1387, 0, '2022-10-05 13:25:00', 1, 3, 10, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1388, 0, '2022-10-05 13:25:00', 1, 3, 11, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1389, 0, '2022-10-05 13:25:00', 1, 3, 12, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1390, 0, '2022-10-05 13:25:00', 1, 3, 13, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1391, 0, '2022-10-05 13:25:00', 1, 3, 14, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1392, 0, '2022-10-05 13:25:00', 1, 3, 15, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1393, 0, '2022-10-05 13:25:00', 1, 3, 16, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1394, 0, '2022-10-05 13:25:00', 1, 3, 17, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1395, 0, '2022-10-05 13:25:00', 1, 3, 18, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1396, 0, '2022-10-05 13:25:00', 1, 3, 19, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1397, 0, '2022-10-05 13:25:00', 1, 3, 20, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1398, 0, '2022-10-05 13:25:00', 1, 3, 21, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1399, 0, '2022-10-05 13:25:00', 1, 3, 22, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1400, 0, '2022-10-05 13:25:00', 1, 3, 23, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1401, 0, '2022-10-05 13:25:00', 1, 3, 24, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1402, 0, '2022-10-05 13:25:00', 1, 3, 25, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1403, 0, '2022-10-05 13:25:00', 1, 3, 26, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1404, 0, '2022-10-05 13:25:00', 1, 3, 27, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1405, 0, '2022-10-05 13:25:00', 1, 3, 28, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1406, 0, '2022-10-05 13:25:00', 1, 3, 29, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1407, 0, '2022-10-05 13:25:00', 1, 3, 30, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1408, 0, '2022-10-05 13:25:00', 1, 3, 31, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1409, 0, '2022-10-05 13:25:00', 1, 3, 32, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1410, 0, '2022-10-05 13:25:00', 1, 3, 33, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1411, 0, '2022-10-05 13:25:00', 1, 3, 34, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1412, 0, '2022-10-05 13:25:00', 1, 3, 35, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1413, 0, '2022-10-05 13:25:00', 1, 3, 36, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1414, 0, '2022-10-05 13:25:00', 1, 3, 37, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1415, 0, '2022-10-05 13:25:00', 1, 3, 38, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1416, 0, '2022-10-05 13:25:00', 1, 3, 39, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1417, 0, '2022-10-05 13:25:00', 1, 3, 40, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1418, 0, '2022-10-05 13:25:00', 1, 3, 41, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1419, 0, '2022-10-05 13:25:00', 1, 3, 42, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1420, 0, '2022-10-05 13:30:00', 1, 1, 0, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1421, 0, '2022-10-05 13:30:00', 1, 1, 1, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1422, 0, '2022-10-05 13:30:00', 1, 1, 2, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1423, 0, '2022-10-05 13:30:00', 1, 1, 3, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1424, 0, '2022-10-05 13:30:00', 1, 1, 4, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1425, 0, '2022-10-05 13:30:00', 1, 1, 5, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1426, 0, '2022-10-05 13:30:00', 1, 1, 6, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1427, 0, '2022-10-05 13:30:00', 1, 1, 7, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1428, 0, '2022-10-05 13:30:00', 1, 1, 8, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1429, 0, '2022-10-05 13:30:00', 1, 1, 9, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1430, 0, '2022-10-05 13:30:00', 1, 1, 10, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1431, 0, '2022-10-05 13:30:00', 1, 1, 11, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1432, 0, '2022-10-05 13:30:00', 1, 1, 12, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1433, 0, '2022-10-05 13:30:00', 1, 1, 13, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1434, 0, '2022-10-05 13:30:00', 1, 1, 14, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1435, 0, '2022-10-05 13:30:00', 1, 1, 15, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1436, 0, '2022-10-05 13:30:00', 1, 1, 16, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1437, 0, '2022-10-05 13:30:00', 1, 1, 17, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1438, 0, '2022-10-05 13:30:00', 1, 1, 18, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1439, 0, '2022-10-05 13:30:00', 1, 1, 19, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1440, 0, '2022-10-05 13:30:00', 1, 1, 20, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1441, 0, '2022-10-05 13:30:00', 1, 1, 21, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1442, 0, '2022-10-05 13:30:00', 1, 1, 22, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1443, 0, '2022-10-05 13:30:00', 1, 1, 23, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1444, 0, '2022-10-05 13:30:00', 1, 1, 24, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1445, 0, '2022-10-05 13:30:00', 1, 1, 25, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1446, 0, '2022-10-05 13:30:00', 1, 1, 26, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1447, 0, '2022-10-05 13:30:00', 1, 1, 27, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1448, 0, '2022-10-05 13:30:00', 1, 1, 28, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1449, 0, '2022-10-05 13:30:00', 1, 1, 29, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1450, 0, '2022-10-05 13:30:00', 1, 1, 30, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1451, 0, '2022-10-05 13:30:00', 1, 1, 31, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1452, 0, '2022-10-05 13:30:00', 1, 1, 32, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1453, 0, '2022-10-05 13:30:00', 1, 1, 33, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1454, 0, '2022-10-05 13:30:00', 1, 1, 34, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1455, 0, '2022-10-05 13:30:00', 1, 1, 35, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1456, 0, '2022-10-05 13:30:00', 1, 1, 36, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1457, 0, '2022-10-05 13:30:00', 1, 1, 37, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1458, 0, '2022-10-05 13:30:00', 1, 1, 38, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1459, 0, '2022-10-05 13:30:00', 1, 1, 39, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1460, 0, '2022-10-05 13:30:00', 1, 1, 40, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1461, 0, '2022-10-05 13:30:00', 1, 1, 41, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1462, 0, '2022-10-05 13:30:00', 1, 1, 42, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1463, 0, '2022-10-05 13:30:00', 1, 2, 0, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1464, 0, '2022-10-05 13:30:00', 1, 2, 1, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1465, 0, '2022-10-05 13:30:00', 1, 2, 2, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1466, 0, '2022-10-05 13:30:00', 1, 2, 3, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1467, 0, '2022-10-05 13:30:00', 1, 2, 4, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1468, 0, '2022-10-05 13:30:00', 1, 2, 5, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1469, 0, '2022-10-05 13:30:00', 1, 2, 6, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1470, 0, '2022-10-05 13:30:00', 1, 2, 7, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1471, 0, '2022-10-05 13:30:00', 1, 2, 8, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1472, 0, '2022-10-05 13:30:00', 1, 2, 9, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1473, 0, '2022-10-05 13:30:00', 1, 2, 10, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1474, 0, '2022-10-05 13:30:00', 1, 2, 11, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1475, 0, '2022-10-05 13:30:00', 1, 2, 12, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1476, 0, '2022-10-05 13:30:00', 1, 2, 13, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1477, 0, '2022-10-05 13:30:00', 1, 2, 14, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1478, 0, '2022-10-05 13:30:00', 1, 2, 15, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1479, 0, '2022-10-05 13:30:00', 1, 2, 16, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1480, 0, '2022-10-05 13:30:00', 1, 2, 17, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1481, 0, '2022-10-05 13:30:00', 1, 2, 18, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1482, 0, '2022-10-05 13:30:00', 1, 2, 19, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1483, 0, '2022-10-05 13:30:00', 1, 2, 20, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1484, 0, '2022-10-05 13:30:00', 1, 2, 21, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1485, 0, '2022-10-05 13:30:00', 1, 2, 22, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1486, 0, '2022-10-05 13:30:00', 1, 2, 23, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1487, 0, '2022-10-05 13:30:00', 1, 2, 24, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1488, 0, '2022-10-05 13:30:00', 1, 2, 25, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1489, 0, '2022-10-05 13:30:00', 1, 2, 26, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1490, 0, '2022-10-05 13:30:00', 1, 2, 27, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1491, 0, '2022-10-05 13:30:00', 1, 2, 28, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1492, 0, '2022-10-05 13:30:00', 1, 2, 29, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1493, 0, '2022-10-05 13:30:00', 1, 2, 30, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1494, 0, '2022-10-05 13:30:00', 1, 2, 31, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1495, 0, '2022-10-05 13:30:00', 1, 2, 32, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1496, 0, '2022-10-05 13:30:00', 1, 2, 33, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1497, 0, '2022-10-05 13:30:00', 1, 2, 34, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1498, 0, '2022-10-05 13:30:00', 1, 2, 35, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1499, 0, '2022-10-05 13:30:00', 1, 2, 36, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1500, 0, '2022-10-05 13:30:00', 1, 2, 37, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1501, 0, '2022-10-05 13:30:00', 1, 2, 38, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1502, 0, '2022-10-05 13:30:00', 1, 2, 39, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1503, 0, '2022-10-05 13:30:00', 1, 2, 40, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1504, 0, '2022-10-05 13:30:00', 1, 2, 41, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1505, 0, '2022-10-05 13:30:00', 1, 2, 42, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1506, 0, '2022-10-05 13:30:00', 1, 3, 0, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1507, 0, '2022-10-05 13:30:00', 1, 3, 1, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1508, 0, '2022-10-05 13:30:00', 1, 3, 2, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1509, 0, '2022-10-05 13:30:00', 1, 3, 3, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1510, 0, '2022-10-05 13:30:00', 1, 3, 4, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1511, 0, '2022-10-05 13:30:00', 1, 3, 5, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1512, 0, '2022-10-05 13:30:00', 1, 3, 6, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1513, 0, '2022-10-05 13:30:00', 1, 3, 7, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1514, 0, '2022-10-05 13:30:00', 1, 3, 8, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1515, 0, '2022-10-05 13:30:00', 1, 3, 9, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1516, 0, '2022-10-05 13:30:00', 1, 3, 10, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1517, 0, '2022-10-05 13:30:00', 1, 3, 11, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1518, 0, '2022-10-05 13:30:00', 1, 3, 12, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1519, 0, '2022-10-05 13:30:00', 1, 3, 13, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1520, 0, '2022-10-05 13:30:00', 1, 3, 14, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1521, 0, '2022-10-05 13:30:00', 1, 3, 15, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1522, 0, '2022-10-05 13:30:00', 1, 3, 16, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1523, 0, '2022-10-05 13:30:00', 1, 3, 17, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1524, 0, '2022-10-05 13:30:00', 1, 3, 18, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1525, 0, '2022-10-05 13:30:00', 1, 3, 19, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1526, 0, '2022-10-05 13:30:00', 1, 3, 20, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1527, 0, '2022-10-05 13:30:00', 1, 3, 21, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1528, 0, '2022-10-05 13:30:00', 1, 3, 22, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1529, 0, '2022-10-05 13:30:00', 1, 3, 23, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1530, 0, '2022-10-05 13:30:00', 1, 3, 24, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1531, 0, '2022-10-05 13:30:00', 1, 3, 25, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1532, 0, '2022-10-05 13:30:00', 1, 3, 26, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1533, 0, '2022-10-05 13:30:00', 1, 3, 27, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1534, 0, '2022-10-05 13:30:00', 1, 3, 28, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1535, 0, '2022-10-05 13:30:00', 1, 3, 29, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1536, 0, '2022-10-05 13:30:00', 1, 3, 30, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1537, 0, '2022-10-05 13:30:00', 1, 3, 31, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1538, 0, '2022-10-05 13:30:00', 1, 3, 32, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1539, 0, '2022-10-05 13:30:00', 1, 3, 33, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1540, 0, '2022-10-05 13:30:00', 1, 3, 34, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1541, 0, '2022-10-05 13:30:00', 1, 3, 35, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1542, 0, '2022-10-05 13:30:00', 1, 3, 36, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1543, 0, '2022-10-05 13:30:00', 1, 3, 37, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1544, 0, '2022-10-05 13:30:00', 1, 3, 38, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1545, 0, '2022-10-05 13:30:00', 1, 3, 39, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1546, 0, '2022-10-05 13:30:00', 1, 3, 40, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1547, 0, '2022-10-05 13:30:00', 1, 3, 41, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1548, 0, '2022-10-05 13:30:00', 1, 3, 42, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1549, 0, '2022-10-05 13:35:00', 1, 1, 0, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1550, 0, '2022-10-05 13:35:00', 1, 1, 1, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1551, 0, '2022-10-05 13:35:00', 1, 1, 2, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1552, 0, '2022-10-05 13:35:00', 1, 1, 3, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1553, 0, '2022-10-05 13:35:00', 1, 1, 4, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1554, 0, '2022-10-05 13:35:00', 1, 1, 5, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1555, 0, '2022-10-05 13:35:00', 1, 1, 6, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1556, 0, '2022-10-05 13:35:00', 1, 1, 7, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1557, 0, '2022-10-05 13:35:00', 1, 1, 8, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1558, 0, '2022-10-05 13:35:00', 1, 1, 9, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1559, 0, '2022-10-05 13:35:00', 1, 1, 10, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1560, 0, '2022-10-05 13:35:00', 1, 1, 11, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1561, 0, '2022-10-05 13:35:00', 1, 1, 12, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1562, 0, '2022-10-05 13:35:00', 1, 1, 13, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1563, 0, '2022-10-05 13:35:00', 1, 1, 14, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1564, 0, '2022-10-05 13:35:00', 1, 1, 15, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1565, 0, '2022-10-05 13:35:00', 1, 1, 16, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1566, 0, '2022-10-05 13:35:00', 1, 1, 17, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1567, 0, '2022-10-05 13:35:00', 1, 1, 18, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1568, 0, '2022-10-05 13:35:00', 1, 1, 19, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1569, 0, '2022-10-05 13:35:00', 1, 1, 20, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1570, 0, '2022-10-05 13:35:00', 1, 1, 21, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1571, 0, '2022-10-05 13:35:00', 1, 1, 22, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1572, 0, '2022-10-05 13:35:00', 1, 1, 23, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1573, 0, '2022-10-05 13:35:00', 1, 1, 24, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1574, 0, '2022-10-05 13:35:00', 1, 1, 25, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1575, 0, '2022-10-05 13:35:00', 1, 1, 26, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1576, 0, '2022-10-05 13:35:00', 1, 1, 27, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1577, 0, '2022-10-05 13:35:00', 1, 1, 28, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1578, 0, '2022-10-05 13:35:00', 1, 1, 29, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1579, 0, '2022-10-05 13:35:00', 1, 1, 30, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1580, 0, '2022-10-05 13:35:00', 1, 1, 31, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1581, 0, '2022-10-05 13:35:00', 1, 1, 32, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1582, 0, '2022-10-05 13:35:00', 1, 1, 33, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1583, 0, '2022-10-05 13:35:00', 1, 1, 34, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1584, 0, '2022-10-05 13:35:00', 1, 1, 35, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1585, 0, '2022-10-05 13:35:00', 1, 1, 36, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1586, 0, '2022-10-05 13:35:00', 1, 1, 37, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1587, 0, '2022-10-05 13:35:00', 1, 1, 38, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1588, 0, '2022-10-05 13:35:00', 1, 1, 39, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1589, 0, '2022-10-05 13:35:00', 1, 1, 40, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1590, 0, '2022-10-05 13:35:00', 1, 1, 41, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1591, 0, '2022-10-05 13:35:00', 1, 1, 42, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1592, 0, '2022-10-05 13:35:00', 1, 2, 0, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1593, 0, '2022-10-05 13:35:00', 1, 2, 1, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1594, 0, '2022-10-05 13:35:00', 1, 2, 2, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1595, 0, '2022-10-05 13:35:00', 1, 2, 3, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1596, 0, '2022-10-05 13:35:00', 1, 2, 4, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1597, 0, '2022-10-05 13:35:00', 1, 2, 5, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1598, 0, '2022-10-05 13:35:00', 1, 2, 6, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1599, 0, '2022-10-05 13:35:00', 1, 2, 7, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1600, 0, '2022-10-05 13:35:00', 1, 2, 8, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1601, 0, '2022-10-05 13:35:00', 1, 2, 9, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1602, 0, '2022-10-05 13:35:00', 1, 2, 10, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1603, 0, '2022-10-05 13:35:00', 1, 2, 11, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1604, 0, '2022-10-05 13:35:00', 1, 2, 12, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1605, 0, '2022-10-05 13:35:00', 1, 2, 13, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1606, 0, '2022-10-05 13:35:00', 1, 2, 14, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1607, 0, '2022-10-05 13:35:00', 1, 2, 15, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1608, 0, '2022-10-05 13:35:00', 1, 2, 16, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1609, 0, '2022-10-05 13:35:00', 1, 2, 17, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1610, 0, '2022-10-05 13:35:00', 1, 2, 18, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1611, 0, '2022-10-05 13:35:00', 1, 2, 19, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1612, 0, '2022-10-05 13:35:00', 1, 2, 20, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1613, 0, '2022-10-05 13:35:00', 1, 2, 21, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1614, 0, '2022-10-05 13:35:00', 1, 2, 22, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1615, 0, '2022-10-05 13:35:00', 1, 2, 23, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1616, 0, '2022-10-05 13:35:00', 1, 2, 24, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1617, 0, '2022-10-05 13:35:00', 1, 2, 25, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1618, 0, '2022-10-05 13:35:00', 1, 2, 26, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1619, 0, '2022-10-05 13:35:00', 1, 2, 27, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1620, 0, '2022-10-05 13:35:00', 1, 2, 28, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1621, 0, '2022-10-05 13:35:00', 1, 2, 29, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1622, 0, '2022-10-05 13:35:00', 1, 2, 30, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1623, 0, '2022-10-05 13:35:00', 1, 2, 31, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1624, 0, '2022-10-05 13:35:00', 1, 2, 32, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1625, 0, '2022-10-05 13:35:00', 1, 2, 33, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1626, 0, '2022-10-05 13:35:00', 1, 2, 34, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1627, 0, '2022-10-05 13:35:00', 1, 2, 35, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1628, 0, '2022-10-05 13:35:00', 1, 2, 36, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1629, 0, '2022-10-05 13:35:00', 1, 2, 37, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1630, 0, '2022-10-05 13:35:00', 1, 2, 38, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1631, 0, '2022-10-05 13:35:00', 1, 2, 39, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1632, 0, '2022-10-05 13:35:00', 1, 2, 40, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1633, 0, '2022-10-05 13:35:00', 1, 2, 41, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1634, 0, '2022-10-05 13:35:00', 1, 2, 42, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1635, 0, '2022-10-05 13:35:00', 1, 3, 0, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1636, 0, '2022-10-05 13:35:00', 1, 3, 1, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1637, 0, '2022-10-05 13:35:00', 1, 3, 2, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1638, 0, '2022-10-05 13:35:00', 1, 3, 3, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1639, 0, '2022-10-05 13:35:00', 1, 3, 4, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1640, 0, '2022-10-05 13:35:00', 1, 3, 5, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1641, 0, '2022-10-05 13:35:00', 1, 3, 6, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1642, 0, '2022-10-05 13:35:00', 1, 3, 7, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1643, 0, '2022-10-05 13:35:00', 1, 3, 8, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1644, 0, '2022-10-05 13:35:00', 1, 3, 9, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1645, 0, '2022-10-05 13:35:00', 1, 3, 10, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1646, 0, '2022-10-05 13:35:00', 1, 3, 11, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1647, 0, '2022-10-05 13:35:00', 1, 3, 12, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1648, 0, '2022-10-05 13:35:00', 1, 3, 13, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1649, 0, '2022-10-05 13:35:00', 1, 3, 14, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1650, 0, '2022-10-05 13:35:00', 1, 3, 15, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1651, 0, '2022-10-05 13:35:00', 1, 3, 16, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1652, 0, '2022-10-05 13:35:00', 1, 3, 17, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1653, 0, '2022-10-05 13:35:00', 1, 3, 18, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1654, 0, '2022-10-05 13:35:00', 1, 3, 19, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1655, 0, '2022-10-05 13:35:00', 1, 3, 20, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1656, 0, '2022-10-05 13:35:00', 1, 3, 21, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1657, 0, '2022-10-05 13:35:00', 1, 3, 22, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1658, 0, '2022-10-05 13:35:00', 1, 3, 23, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1659, 0, '2022-10-05 13:35:00', 1, 3, 24, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1660, 0, '2022-10-05 13:35:00', 1, 3, 25, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1661, 0, '2022-10-05 13:35:00', 1, 3, 26, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1662, 0, '2022-10-05 13:35:00', 1, 3, 27, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1663, 0, '2022-10-05 13:35:00', 1, 3, 28, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1664, 0, '2022-10-05 13:35:00', 1, 3, 29, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1665, 0, '2022-10-05 13:35:00', 1, 3, 30, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1666, 0, '2022-10-05 13:35:00', 1, 3, 31, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1667, 0, '2022-10-05 13:35:00', 1, 3, 32, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1668, 0, '2022-10-05 13:35:00', 1, 3, 33, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1669, 0, '2022-10-05 13:35:00', 1, 3, 34, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1670, 0, '2022-10-05 13:35:00', 1, 3, 35, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1671, 0, '2022-10-05 13:35:00', 1, 3, 36, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1672, 0, '2022-10-05 13:35:00', 1, 3, 37, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1673, 0, '2022-10-05 13:35:00', 1, 3, 38, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1674, 0, '2022-10-05 13:35:00', 1, 3, 39, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1675, 0, '2022-10-05 13:35:00', 1, 3, 40, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1676, 0, '2022-10-05 13:35:00', 1, 3, 41, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1677, 0, '2022-10-05 13:35:00', 1, 3, 42, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1678, 0, '2022-10-05 13:40:00', 1, 1, 0, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1679, 0, '2022-10-05 13:40:00', 1, 1, 1, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1680, 0, '2022-10-05 13:40:00', 1, 1, 2, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1681, 0, '2022-10-05 13:40:00', 1, 1, 3, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1682, 0, '2022-10-05 13:40:00', 1, 1, 4, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1683, 0, '2022-10-05 13:40:00', 1, 1, 5, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1684, 0, '2022-10-05 13:40:00', 1, 1, 6, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1685, 0, '2022-10-05 13:40:00', 1, 1, 7, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1686, 0, '2022-10-05 13:40:00', 1, 1, 8, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1687, 0, '2022-10-05 13:40:00', 1, 1, 9, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1688, 0, '2022-10-05 13:40:00', 1, 1, 10, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1689, 0, '2022-10-05 13:40:00', 1, 1, 11, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1690, 0, '2022-10-05 13:40:00', 1, 1, 12, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1691, 0, '2022-10-05 13:40:00', 1, 1, 13, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1692, 0, '2022-10-05 13:40:00', 1, 1, 14, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1693, 0, '2022-10-05 13:40:00', 1, 1, 15, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1694, 0, '2022-10-05 13:40:00', 1, 1, 16, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1695, 0, '2022-10-05 13:40:00', 1, 1, 17, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1696, 0, '2022-10-05 13:40:00', 1, 1, 18, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1697, 0, '2022-10-05 13:40:00', 1, 1, 19, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1698, 0, '2022-10-05 13:40:00', 1, 1, 20, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1699, 0, '2022-10-05 13:40:00', 1, 1, 21, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1700, 0, '2022-10-05 13:40:00', 1, 1, 22, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1701, 0, '2022-10-05 13:40:00', 1, 1, 23, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1702, 0, '2022-10-05 13:40:00', 1, 1, 24, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1703, 0, '2022-10-05 13:40:00', 1, 1, 25, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1704, 0, '2022-10-05 13:40:00', 1, 1, 26, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1705, 0, '2022-10-05 13:40:00', 1, 1, 27, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1706, 0, '2022-10-05 13:40:00', 1, 1, 28, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1707, 0, '2022-10-05 13:40:00', 1, 1, 29, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1708, 0, '2022-10-05 13:40:00', 1, 1, 30, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1709, 0, '2022-10-05 13:40:00', 1, 1, 31, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1710, 0, '2022-10-05 13:40:00', 1, 1, 32, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1711, 0, '2022-10-05 13:40:00', 1, 1, 33, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1712, 0, '2022-10-05 13:40:00', 1, 1, 34, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1713, 0, '2022-10-05 13:40:00', 1, 1, 35, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1714, 0, '2022-10-05 13:40:00', 1, 1, 36, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1715, 0, '2022-10-05 13:40:00', 1, 1, 37, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1716, 0, '2022-10-05 13:40:00', 1, 1, 38, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1717, 0, '2022-10-05 13:40:00', 1, 1, 39, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1718, 0, '2022-10-05 13:40:00', 1, 1, 40, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1719, 0, '2022-10-05 13:40:00', 1, 1, 41, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1720, 0, '2022-10-05 13:40:00', 1, 1, 42, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1721, 0, '2022-10-05 13:40:00', 1, 2, 0, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1722, 0, '2022-10-05 13:40:00', 1, 2, 1, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1723, 0, '2022-10-05 13:40:00', 1, 2, 2, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1724, 0, '2022-10-05 13:40:00', 1, 2, 3, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1725, 0, '2022-10-05 13:40:00', 1, 2, 4, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1726, 0, '2022-10-05 13:40:00', 1, 2, 5, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1727, 0, '2022-10-05 13:40:00', 1, 2, 6, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1728, 0, '2022-10-05 13:40:00', 1, 2, 7, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1729, 0, '2022-10-05 13:40:00', 1, 2, 8, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1730, 0, '2022-10-05 13:40:00', 1, 2, 9, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1731, 0, '2022-10-05 13:40:00', 1, 2, 10, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1732, 0, '2022-10-05 13:40:00', 1, 2, 11, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1733, 0, '2022-10-05 13:40:00', 1, 2, 12, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1734, 0, '2022-10-05 13:40:00', 1, 2, 13, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1735, 0, '2022-10-05 13:40:00', 1, 2, 14, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1736, 0, '2022-10-05 13:40:00', 1, 2, 15, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1737, 0, '2022-10-05 13:40:00', 1, 2, 16, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1738, 0, '2022-10-05 13:40:00', 1, 2, 17, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1739, 0, '2022-10-05 13:40:00', 1, 2, 18, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1740, 0, '2022-10-05 13:40:00', 1, 2, 19, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1741, 0, '2022-10-05 13:40:00', 1, 2, 20, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1742, 0, '2022-10-05 13:40:00', 1, 2, 21, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1743, 0, '2022-10-05 13:40:00', 1, 2, 22, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1744, 0, '2022-10-05 13:40:00', 1, 2, 23, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1745, 0, '2022-10-05 13:40:00', 1, 2, 24, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1746, 0, '2022-10-05 13:40:00', 1, 2, 25, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1747, 0, '2022-10-05 13:40:00', 1, 2, 26, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1748, 0, '2022-10-05 13:40:00', 1, 2, 27, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1749, 0, '2022-10-05 13:40:00', 1, 2, 28, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1750, 0, '2022-10-05 13:40:00', 1, 2, 29, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1751, 0, '2022-10-05 13:40:00', 1, 2, 30, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1752, 0, '2022-10-05 13:40:00', 1, 2, 31, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1753, 0, '2022-10-05 13:40:00', 1, 2, 32, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1754, 0, '2022-10-05 13:40:00', 1, 2, 33, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1755, 0, '2022-10-05 13:40:00', 1, 2, 34, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1756, 0, '2022-10-05 13:40:00', 1, 2, 35, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1757, 0, '2022-10-05 13:40:00', 1, 2, 36, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1758, 0, '2022-10-05 13:40:00', 1, 2, 37, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1759, 0, '2022-10-05 13:40:00', 1, 2, 38, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1760, 0, '2022-10-05 13:40:00', 1, 2, 39, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1761, 0, '2022-10-05 13:40:00', 1, 2, 40, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1762, 0, '2022-10-05 13:40:00', 1, 2, 41, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1763, 0, '2022-10-05 13:40:00', 1, 2, 42, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1764, 0, '2022-10-05 13:40:00', 1, 3, 0, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1765, 0, '2022-10-05 13:40:00', 1, 3, 1, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1766, 0, '2022-10-05 13:40:00', 1, 3, 2, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1767, 0, '2022-10-05 13:40:00', 1, 3, 3, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1768, 0, '2022-10-05 13:40:00', 1, 3, 4, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1769, 0, '2022-10-05 13:40:00', 1, 3, 5, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1770, 0, '2022-10-05 13:40:00', 1, 3, 6, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1771, 0, '2022-10-05 13:40:00', 1, 3, 7, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1772, 0, '2022-10-05 13:40:00', 1, 3, 8, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1773, 0, '2022-10-05 13:40:00', 1, 3, 9, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1774, 0, '2022-10-05 13:40:00', 1, 3, 10, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1775, 0, '2022-10-05 13:40:00', 1, 3, 11, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1776, 0, '2022-10-05 13:40:00', 1, 3, 12, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1777, 0, '2022-10-05 13:40:00', 1, 3, 13, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1778, 0, '2022-10-05 13:40:00', 1, 3, 14, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1779, 0, '2022-10-05 13:40:00', 1, 3, 15, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1780, 0, '2022-10-05 13:40:00', 1, 3, 16, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1781, 0, '2022-10-05 13:40:00', 1, 3, 17, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1782, 0, '2022-10-05 13:40:00', 1, 3, 18, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1783, 0, '2022-10-05 13:40:00', 1, 3, 19, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1784, 0, '2022-10-05 13:40:00', 1, 3, 20, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1785, 0, '2022-10-05 13:40:00', 1, 3, 21, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1786, 0, '2022-10-05 13:40:00', 1, 3, 22, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1787, 0, '2022-10-05 13:40:00', 1, 3, 23, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1788, 0, '2022-10-05 13:40:00', 1, 3, 24, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1789, 0, '2022-10-05 13:40:00', 1, 3, 25, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1790, 0, '2022-10-05 13:40:00', 1, 3, 26, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1791, 0, '2022-10-05 13:40:00', 1, 3, 27, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1792, 0, '2022-10-05 13:40:00', 1, 3, 28, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1793, 0, '2022-10-05 13:40:00', 1, 3, 29, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1794, 0, '2022-10-05 13:40:00', 1, 3, 30, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1795, 0, '2022-10-05 13:40:00', 1, 3, 31, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1796, 0, '2022-10-05 13:40:00', 1, 3, 32, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1797, 0, '2022-10-05 13:40:00', 1, 3, 33, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1798, 0, '2022-10-05 13:40:00', 1, 3, 34, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1799, 0, '2022-10-05 13:40:00', 1, 3, 35, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1800, 0, '2022-10-05 13:40:00', 1, 3, 36, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1801, 0, '2022-10-05 13:40:00', 1, 3, 37, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1802, 0, '2022-10-05 13:40:00', 1, 3, 38, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1803, 0, '2022-10-05 13:40:00', 1, 3, 39, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1804, 0, '2022-10-05 13:40:00', 1, 3, 40, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1805, 0, '2022-10-05 13:40:00', 1, 3, 41, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1806, 0, '2022-10-05 13:40:00', 1, 3, 42, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1807, 0, '2022-10-05 13:45:00', 1, 1, 0, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1808, 0, '2022-10-05 13:45:00', 1, 1, 1, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1809, 0, '2022-10-05 13:45:00', 1, 1, 2, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1810, 0, '2022-10-05 13:45:00', 1, 1, 3, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1811, 0, '2022-10-05 13:45:00', 1, 1, 4, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1812, 0, '2022-10-05 13:45:00', 1, 1, 5, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1813, 0, '2022-10-05 13:45:00', 1, 1, 6, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1814, 0, '2022-10-05 13:45:00', 1, 1, 7, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1815, 0, '2022-10-05 13:45:00', 1, 1, 8, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1816, 0, '2022-10-05 13:45:00', 1, 1, 9, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1817, 0, '2022-10-05 13:45:00', 1, 1, 10, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1818, 0, '2022-10-05 13:45:00', 1, 1, 11, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1819, 0, '2022-10-05 13:45:00', 1, 1, 12, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1820, 0, '2022-10-05 13:45:00', 1, 1, 13, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1821, 0, '2022-10-05 13:45:00', 1, 1, 14, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1822, 0, '2022-10-05 13:45:00', 1, 1, 15, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1823, 0, '2022-10-05 13:45:00', 1, 1, 16, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1824, 0, '2022-10-05 13:45:00', 1, 1, 17, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1825, 0, '2022-10-05 13:45:00', 1, 1, 18, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1826, 0, '2022-10-05 13:45:00', 1, 1, 19, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1827, 0, '2022-10-05 13:45:00', 1, 1, 20, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1828, 0, '2022-10-05 13:45:00', 1, 1, 21, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1829, 0, '2022-10-05 13:45:00', 1, 1, 22, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1830, 0, '2022-10-05 13:45:00', 1, 1, 23, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1831, 0, '2022-10-05 13:45:00', 1, 1, 24, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1832, 0, '2022-10-05 13:45:00', 1, 1, 25, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1833, 0, '2022-10-05 13:45:00', 1, 1, 26, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1834, 0, '2022-10-05 13:45:00', 1, 1, 27, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1835, 0, '2022-10-05 13:45:00', 1, 1, 28, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1836, 0, '2022-10-05 13:45:00', 1, 1, 29, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1837, 0, '2022-10-05 13:45:00', 1, 1, 30, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1838, 0, '2022-10-05 13:45:00', 1, 1, 31, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1839, 0, '2022-10-05 13:45:00', 1, 1, 32, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1840, 0, '2022-10-05 13:45:00', 1, 1, 33, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1841, 0, '2022-10-05 13:45:00', 1, 1, 34, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1842, 0, '2022-10-05 13:45:00', 1, 1, 35, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1843, 0, '2022-10-05 13:45:00', 1, 1, 36, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1844, 0, '2022-10-05 13:45:00', 1, 1, 37, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1845, 0, '2022-10-05 13:45:00', 1, 1, 38, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1846, 0, '2022-10-05 13:45:00', 1, 1, 39, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1847, 0, '2022-10-05 13:45:00', 1, 1, 40, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1848, 0, '2022-10-05 13:45:00', 1, 1, 41, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1849, 0, '2022-10-05 13:45:00', 1, 1, 42, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1850, 0, '2022-10-05 13:45:00', 1, 2, 0, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1851, 0, '2022-10-05 13:45:00', 1, 2, 1, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1852, 0, '2022-10-05 13:45:00', 1, 2, 2, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1853, 0, '2022-10-05 13:45:00', 1, 2, 3, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1854, 0, '2022-10-05 13:45:00', 1, 2, 4, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1855, 0, '2022-10-05 13:45:00', 1, 2, 5, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1856, 0, '2022-10-05 13:45:00', 1, 2, 6, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1857, 0, '2022-10-05 13:45:00', 1, 2, 7, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1858, 0, '2022-10-05 13:45:00', 1, 2, 8, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1859, 0, '2022-10-05 13:45:00', 1, 2, 9, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1860, 0, '2022-10-05 13:45:00', 1, 2, 10, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1861, 0, '2022-10-05 13:45:00', 1, 2, 11, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1862, 0, '2022-10-05 13:45:00', 1, 2, 12, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1863, 0, '2022-10-05 13:45:00', 1, 2, 13, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1864, 0, '2022-10-05 13:45:00', 1, 2, 14, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1865, 0, '2022-10-05 13:45:00', 1, 2, 15, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1866, 0, '2022-10-05 13:45:00', 1, 2, 16, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1867, 0, '2022-10-05 13:45:00', 1, 2, 17, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1868, 0, '2022-10-05 13:45:00', 1, 2, 18, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1869, 0, '2022-10-05 13:45:00', 1, 2, 19, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1870, 0, '2022-10-05 13:45:00', 1, 2, 20, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1871, 0, '2022-10-05 13:45:00', 1, 2, 21, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1872, 0, '2022-10-05 13:45:00', 1, 2, 22, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1873, 0, '2022-10-05 13:45:00', 1, 2, 23, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1874, 0, '2022-10-05 13:45:00', 1, 2, 24, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1875, 0, '2022-10-05 13:45:00', 1, 2, 25, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1876, 0, '2022-10-05 13:45:00', 1, 2, 26, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1877, 0, '2022-10-05 13:45:00', 1, 2, 27, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1878, 0, '2022-10-05 13:45:00', 1, 2, 28, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1879, 0, '2022-10-05 13:45:00', 1, 2, 29, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1880, 0, '2022-10-05 13:45:00', 1, 2, 30, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1881, 0, '2022-10-05 13:45:00', 1, 2, 31, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1882, 0, '2022-10-05 13:45:00', 1, 2, 32, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1883, 0, '2022-10-05 13:45:00', 1, 2, 33, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1884, 0, '2022-10-05 13:45:00', 1, 2, 34, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1885, 0, '2022-10-05 13:45:00', 1, 2, 35, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1886, 0, '2022-10-05 13:45:00', 1, 2, 36, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1887, 0, '2022-10-05 13:45:00', 1, 2, 37, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1888, 0, '2022-10-05 13:45:00', 1, 2, 38, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1889, 0, '2022-10-05 13:45:00', 1, 2, 39, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1890, 0, '2022-10-05 13:45:00', 1, 2, 40, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1891, 0, '2022-10-05 13:45:00', 1, 2, 41, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1892, 0, '2022-10-05 13:45:00', 1, 2, 42, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1893, 0, '2022-10-05 13:45:00', 1, 3, 0, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1894, 0, '2022-10-05 13:45:00', 1, 3, 1, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1895, 0, '2022-10-05 13:45:00', 1, 3, 2, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1896, 0, '2022-10-05 13:45:00', 1, 3, 3, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1897, 0, '2022-10-05 13:45:00', 1, 3, 4, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1898, 0, '2022-10-05 13:45:00', 1, 3, 5, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1899, 0, '2022-10-05 13:45:00', 1, 3, 6, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1900, 0, '2022-10-05 13:45:00', 1, 3, 7, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1901, 0, '2022-10-05 13:45:00', 1, 3, 8, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1902, 0, '2022-10-05 13:45:00', 1, 3, 9, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1903, 0, '2022-10-05 13:45:00', 1, 3, 10, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1904, 0, '2022-10-05 13:45:00', 1, 3, 11, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1905, 0, '2022-10-05 13:45:00', 1, 3, 12, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1906, 0, '2022-10-05 13:45:00', 1, 3, 13, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1907, 0, '2022-10-05 13:45:00', 1, 3, 14, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1908, 0, '2022-10-05 13:45:00', 1, 3, 15, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1909, 0, '2022-10-05 13:45:00', 1, 3, 16, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1910, 0, '2022-10-05 13:45:00', 1, 3, 17, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1911, 0, '2022-10-05 13:45:00', 1, 3, 18, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1912, 0, '2022-10-05 13:45:00', 1, 3, 19, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1913, 0, '2022-10-05 13:45:00', 1, 3, 20, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1914, 0, '2022-10-05 13:45:00', 1, 3, 21, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1915, 0, '2022-10-05 13:45:00', 1, 3, 22, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1916, 0, '2022-10-05 13:45:00', 1, 3, 23, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1917, 0, '2022-10-05 13:45:00', 1, 3, 24, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1918, 0, '2022-10-05 13:45:00', 1, 3, 25, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1919, 0, '2022-10-05 13:45:00', 1, 3, 26, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1920, 0, '2022-10-05 13:45:00', 1, 3, 27, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1921, 0, '2022-10-05 13:45:00', 1, 3, 28, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1922, 0, '2022-10-05 13:45:00', 1, 3, 29, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1923, 0, '2022-10-05 13:45:00', 1, 3, 30, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1924, 0, '2022-10-05 13:45:00', 1, 3, 31, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1925, 0, '2022-10-05 13:45:00', 1, 3, 32, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1926, 0, '2022-10-05 13:45:00', 1, 3, 33, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1927, 0, '2022-10-05 13:45:00', 1, 3, 34, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1928, 0, '2022-10-05 13:45:00', 1, 3, 35, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1929, 0, '2022-10-05 13:45:00', 1, 3, 36, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1930, 0, '2022-10-05 13:45:00', 1, 3, 37, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1931, 0, '2022-10-05 13:45:00', 1, 3, 38, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1932, 0, '2022-10-05 13:45:00', 1, 3, 39, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1933, 0, '2022-10-05 13:45:00', 1, 3, 40, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1934, 0, '2022-10-05 13:45:00', 1, 3, 41, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1935, 0, '2022-10-05 13:45:00', 1, 3, 42, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1936, 0, '2022-10-05 13:50:00', 1, 1, 0, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1937, 0, '2022-10-05 13:50:00', 1, 1, 1, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1938, 0, '2022-10-05 13:50:00', 1, 1, 2, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1939, 0, '2022-10-05 13:50:00', 1, 1, 3, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1940, 0, '2022-10-05 13:50:00', 1, 1, 4, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1941, 0, '2022-10-05 13:50:00', 1, 1, 5, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1942, 0, '2022-10-05 13:50:00', 1, 1, 6, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1943, 0, '2022-10-05 13:50:00', 1, 1, 7, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1944, 0, '2022-10-05 13:50:00', 1, 1, 8, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1945, 0, '2022-10-05 13:50:00', 1, 1, 9, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1946, 0, '2022-10-05 13:50:00', 1, 1, 10, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1947, 0, '2022-10-05 13:50:00', 1, 1, 11, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1948, 0, '2022-10-05 13:50:00', 1, 1, 12, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1949, 0, '2022-10-05 13:50:00', 1, 1, 13, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1950, 0, '2022-10-05 13:50:00', 1, 1, 14, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1951, 0, '2022-10-05 13:50:00', 1, 1, 15, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1952, 0, '2022-10-05 13:50:00', 1, 1, 16, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1953, 0, '2022-10-05 13:50:00', 1, 1, 17, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1954, 0, '2022-10-05 13:50:00', 1, 1, 18, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1955, 0, '2022-10-05 13:50:00', 1, 1, 19, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1956, 0, '2022-10-05 13:50:00', 1, 1, 20, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1957, 0, '2022-10-05 13:50:00', 1, 1, 21, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1958, 0, '2022-10-05 13:50:00', 1, 1, 22, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1959, 0, '2022-10-05 13:50:00', 1, 1, 23, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1960, 0, '2022-10-05 13:50:00', 1, 1, 24, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1961, 0, '2022-10-05 13:50:00', 1, 1, 25, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1962, 0, '2022-10-05 13:50:00', 1, 1, 26, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1963, 0, '2022-10-05 13:50:00', 1, 1, 27, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1964, 0, '2022-10-05 13:50:00', 1, 1, 28, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1965, 0, '2022-10-05 13:50:00', 1, 1, 29, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1966, 0, '2022-10-05 13:50:00', 1, 1, 30, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1967, 0, '2022-10-05 13:50:00', 1, 1, 31, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1968, 0, '2022-10-05 13:50:00', 1, 1, 32, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1969, 0, '2022-10-05 13:50:00', 1, 1, 33, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1970, 0, '2022-10-05 13:50:00', 1, 1, 34, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1971, 0, '2022-10-05 13:50:00', 1, 1, 35, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1972, 0, '2022-10-05 13:50:00', 1, 1, 36, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1973, 0, '2022-10-05 13:50:00', 1, 1, 37, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1974, 0, '2022-10-05 13:50:00', 1, 1, 38, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1975, 0, '2022-10-05 13:50:00', 1, 1, 39, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1976, 0, '2022-10-05 13:50:00', 1, 1, 40, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1977, 0, '2022-10-05 13:50:00', 1, 1, 41, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1978, 0, '2022-10-05 13:50:00', 1, 1, 42, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1979, 0, '2022-10-05 13:50:00', 1, 2, 0, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1980, 0, '2022-10-05 13:50:00', 1, 2, 1, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1981, 0, '2022-10-05 13:50:00', 1, 2, 2, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1982, 0, '2022-10-05 13:50:00', 1, 2, 3, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1983, 0, '2022-10-05 13:50:00', 1, 2, 4, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1984, 0, '2022-10-05 13:50:00', 1, 2, 5, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1985, 0, '2022-10-05 13:50:00', 1, 2, 6, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1986, 0, '2022-10-05 13:50:00', 1, 2, 7, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1987, 0, '2022-10-05 13:50:00', 1, 2, 8, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1988, 0, '2022-10-05 13:50:00', 1, 2, 9, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1989, 0, '2022-10-05 13:50:00', 1, 2, 10, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1990, 0, '2022-10-05 13:50:00', 1, 2, 11, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1991, 0, '2022-10-05 13:50:00', 1, 2, 12, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1992, 0, '2022-10-05 13:50:00', 1, 2, 13, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1993, 0, '2022-10-05 13:50:00', 1, 2, 14, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1994, 0, '2022-10-05 13:50:00', 1, 2, 15, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1995, 0, '2022-10-05 13:50:00', 1, 2, 16, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1996, 0, '2022-10-05 13:50:00', 1, 2, 17, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1997, 0, '2022-10-05 13:50:00', 1, 2, 18, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1998, 0, '2022-10-05 13:50:00', 1, 2, 19, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (1999, 0, '2022-10-05 13:50:00', 1, 2, 20, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2000, 0, '2022-10-05 13:50:00', 1, 2, 21, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2001, 0, '2022-10-05 13:50:00', 1, 2, 22, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2002, 0, '2022-10-05 13:50:00', 1, 2, 23, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2003, 0, '2022-10-05 13:50:00', 1, 2, 24, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2004, 0, '2022-10-05 13:50:00', 1, 2, 25, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2005, 0, '2022-10-05 13:50:00', 1, 2, 26, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2006, 0, '2022-10-05 13:50:00', 1, 2, 27, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2007, 0, '2022-10-05 13:50:00', 1, 2, 28, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2008, 0, '2022-10-05 13:50:00', 1, 2, 29, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2009, 0, '2022-10-05 13:50:00', 1, 2, 30, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2010, 0, '2022-10-05 13:50:00', 1, 2, 31, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2011, 0, '2022-10-05 13:50:00', 1, 2, 32, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2012, 0, '2022-10-05 13:50:00', 1, 2, 33, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2013, 0, '2022-10-05 13:50:00', 1, 2, 34, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2014, 0, '2022-10-05 13:50:00', 1, 2, 35, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2015, 0, '2022-10-05 13:50:00', 1, 2, 36, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2016, 0, '2022-10-05 13:50:00', 1, 2, 37, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2017, 0, '2022-10-05 13:50:00', 1, 2, 38, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2018, 0, '2022-10-05 13:50:00', 1, 2, 39, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2019, 0, '2022-10-05 13:50:00', 1, 2, 40, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2020, 0, '2022-10-05 13:50:00', 1, 2, 41, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2021, 0, '2022-10-05 13:50:00', 1, 2, 42, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2022, 0, '2022-10-05 13:50:00', 1, 3, 0, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2023, 0, '2022-10-05 13:50:00', 1, 3, 1, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2024, 0, '2022-10-05 13:50:00', 1, 3, 2, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2025, 0, '2022-10-05 13:50:00', 1, 3, 3, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2026, 0, '2022-10-05 13:50:00', 1, 3, 4, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2027, 0, '2022-10-05 13:50:00', 1, 3, 5, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2028, 0, '2022-10-05 13:50:00', 1, 3, 6, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2029, 0, '2022-10-05 13:50:00', 1, 3, 7, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2030, 0, '2022-10-05 13:50:00', 1, 3, 8, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2031, 0, '2022-10-05 13:50:00', 1, 3, 9, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2032, 0, '2022-10-05 13:50:00', 1, 3, 10, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2033, 0, '2022-10-05 13:50:00', 1, 3, 11, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2034, 0, '2022-10-05 13:50:00', 1, 3, 12, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2035, 0, '2022-10-05 13:50:00', 1, 3, 13, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2036, 0, '2022-10-05 13:50:00', 1, 3, 14, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2037, 0, '2022-10-05 13:50:00', 1, 3, 15, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2038, 0, '2022-10-05 13:50:00', 1, 3, 16, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2039, 0, '2022-10-05 13:50:00', 1, 3, 17, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2040, 0, '2022-10-05 13:50:00', 1, 3, 18, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2041, 0, '2022-10-05 13:50:00', 1, 3, 19, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2042, 0, '2022-10-05 13:50:00', 1, 3, 20, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2043, 0, '2022-10-05 13:50:00', 1, 3, 21, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2044, 0, '2022-10-05 13:50:00', 1, 3, 22, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2045, 0, '2022-10-05 13:50:00', 1, 3, 23, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2046, 0, '2022-10-05 13:50:00', 1, 3, 24, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2047, 0, '2022-10-05 13:50:00', 1, 3, 25, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2048, 0, '2022-10-05 13:50:00', 1, 3, 26, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2049, 0, '2022-10-05 13:50:00', 1, 3, 27, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2050, 0, '2022-10-05 13:50:00', 1, 3, 28, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2051, 0, '2022-10-05 13:50:00', 1, 3, 29, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2052, 0, '2022-10-05 13:50:00', 1, 3, 30, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2053, 0, '2022-10-05 13:50:00', 1, 3, 31, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2054, 0, '2022-10-05 13:50:00', 1, 3, 32, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2055, 0, '2022-10-05 13:50:00', 1, 3, 33, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2056, 0, '2022-10-05 13:50:00', 1, 3, 34, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2057, 0, '2022-10-05 13:50:00', 1, 3, 35, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2058, 0, '2022-10-05 13:50:00', 1, 3, 36, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2059, 0, '2022-10-05 13:50:00', 1, 3, 37, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2060, 0, '2022-10-05 13:50:00', 1, 3, 38, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2061, 0, '2022-10-05 13:50:00', 1, 3, 39, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2062, 0, '2022-10-05 13:50:00', 1, 3, 40, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2063, 0, '2022-10-05 13:50:00', 1, 3, 41, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2064, 0, '2022-10-05 13:50:00', 1, 3, 42, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2065, 0, '2022-10-05 13:55:00', 1, 1, 0, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2066, 0, '2022-10-05 13:55:00', 1, 1, 1, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2067, 0, '2022-10-05 13:55:00', 1, 1, 2, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2068, 0, '2022-10-05 13:55:00', 1, 1, 3, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2069, 0, '2022-10-05 13:55:00', 1, 1, 4, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2070, 0, '2022-10-05 13:55:00', 1, 1, 5, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2071, 0, '2022-10-05 13:55:00', 1, 1, 6, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2072, 0, '2022-10-05 13:55:00', 1, 1, 7, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2073, 0, '2022-10-05 13:55:00', 1, 1, 8, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2074, 0, '2022-10-05 13:55:00', 1, 1, 9, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2075, 0, '2022-10-05 13:55:00', 1, 1, 10, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2076, 0, '2022-10-05 13:55:00', 1, 1, 11, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2077, 0, '2022-10-05 13:55:00', 1, 1, 12, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2078, 0, '2022-10-05 13:55:00', 1, 1, 13, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2079, 0, '2022-10-05 13:55:00', 1, 1, 14, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2080, 0, '2022-10-05 13:55:00', 1, 1, 15, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2081, 0, '2022-10-05 13:55:00', 1, 1, 16, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2082, 0, '2022-10-05 13:55:00', 1, 1, 17, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2083, 0, '2022-10-05 13:55:00', 1, 1, 18, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2084, 0, '2022-10-05 13:55:00', 1, 1, 19, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2085, 0, '2022-10-05 13:55:00', 1, 1, 20, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2086, 0, '2022-10-05 13:55:00', 1, 1, 21, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2087, 0, '2022-10-05 13:55:00', 1, 1, 22, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2088, 0, '2022-10-05 13:55:00', 1, 1, 23, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2089, 0, '2022-10-05 13:55:00', 1, 1, 24, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2090, 0, '2022-10-05 13:55:00', 1, 1, 25, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2091, 0, '2022-10-05 13:55:00', 1, 1, 26, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2092, 0, '2022-10-05 13:55:00', 1, 1, 27, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2093, 0, '2022-10-05 13:55:00', 1, 1, 28, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2094, 0, '2022-10-05 13:55:00', 1, 1, 29, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2095, 0, '2022-10-05 13:55:00', 1, 1, 30, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2096, 0, '2022-10-05 13:55:00', 1, 1, 31, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2097, 0, '2022-10-05 13:55:00', 1, 1, 32, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2098, 0, '2022-10-05 13:55:00', 1, 1, 33, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2099, 0, '2022-10-05 13:55:00', 1, 1, 34, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2100, 0, '2022-10-05 13:55:00', 1, 1, 35, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2101, 0, '2022-10-05 13:55:00', 1, 1, 36, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2102, 0, '2022-10-05 13:55:00', 1, 1, 37, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2103, 0, '2022-10-05 13:55:00', 1, 1, 38, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2104, 0, '2022-10-05 13:55:00', 1, 1, 39, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2105, 0, '2022-10-05 13:55:00', 1, 1, 40, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2106, 0, '2022-10-05 13:55:00', 1, 1, 41, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2107, 0, '2022-10-05 13:55:00', 1, 1, 42, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2108, 0, '2022-10-05 13:55:00', 1, 2, 0, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2109, 0, '2022-10-05 13:55:00', 1, 2, 1, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2110, 0, '2022-10-05 13:55:00', 1, 2, 2, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2111, 0, '2022-10-05 13:55:00', 1, 2, 3, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2112, 0, '2022-10-05 13:55:00', 1, 2, 4, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2113, 0, '2022-10-05 13:55:00', 1, 2, 5, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2114, 0, '2022-10-05 13:55:00', 1, 2, 6, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2115, 0, '2022-10-05 13:55:00', 1, 2, 7, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2116, 0, '2022-10-05 13:55:00', 1, 2, 8, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2117, 0, '2022-10-05 13:55:00', 1, 2, 9, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2118, 0, '2022-10-05 13:55:00', 1, 2, 10, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2119, 0, '2022-10-05 13:55:00', 1, 2, 11, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2120, 0, '2022-10-05 13:55:00', 1, 2, 12, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2121, 0, '2022-10-05 13:55:00', 1, 2, 13, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2122, 0, '2022-10-05 13:55:00', 1, 2, 14, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2123, 0, '2022-10-05 13:55:00', 1, 2, 15, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2124, 0, '2022-10-05 13:55:00', 1, 2, 16, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2125, 0, '2022-10-05 13:55:00', 1, 2, 17, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2126, 0, '2022-10-05 13:55:00', 1, 2, 18, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2127, 0, '2022-10-05 13:55:00', 1, 2, 19, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2128, 0, '2022-10-05 13:55:00', 1, 2, 20, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2129, 0, '2022-10-05 13:55:00', 1, 2, 21, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2130, 0, '2022-10-05 13:55:00', 1, 2, 22, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2131, 0, '2022-10-05 13:55:00', 1, 2, 23, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2132, 0, '2022-10-05 13:55:00', 1, 2, 24, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2133, 0, '2022-10-05 13:55:00', 1, 2, 25, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2134, 0, '2022-10-05 13:55:00', 1, 2, 26, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2135, 0, '2022-10-05 13:55:00', 1, 2, 27, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2136, 0, '2022-10-05 13:55:00', 1, 2, 28, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2137, 0, '2022-10-05 13:55:00', 1, 2, 29, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2138, 0, '2022-10-05 13:55:00', 1, 2, 30, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2139, 0, '2022-10-05 13:55:00', 1, 2, 31, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2140, 0, '2022-10-05 13:55:00', 1, 2, 32, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2141, 0, '2022-10-05 13:55:00', 1, 2, 33, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2142, 0, '2022-10-05 13:55:00', 1, 2, 34, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2143, 0, '2022-10-05 13:55:00', 1, 2, 35, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2144, 0, '2022-10-05 13:55:00', 1, 2, 36, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2145, 0, '2022-10-05 13:55:00', 1, 2, 37, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2146, 0, '2022-10-05 13:55:00', 1, 2, 38, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2147, 0, '2022-10-05 13:55:00', 1, 2, 39, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2148, 0, '2022-10-05 13:55:00', 1, 2, 40, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2149, 0, '2022-10-05 13:55:00', 1, 2, 41, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2150, 0, '2022-10-05 13:55:00', 1, 2, 42, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2151, 0, '2022-10-05 13:55:00', 1, 3, 0, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2152, 0, '2022-10-05 13:55:00', 1, 3, 1, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2153, 0, '2022-10-05 13:55:00', 1, 3, 2, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2154, 0, '2022-10-05 13:55:00', 1, 3, 3, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2155, 0, '2022-10-05 13:55:00', 1, 3, 4, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2156, 0, '2022-10-05 13:55:00', 1, 3, 5, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2157, 0, '2022-10-05 13:55:00', 1, 3, 6, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2158, 0, '2022-10-05 13:55:00', 1, 3, 7, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2159, 0, '2022-10-05 13:55:00', 1, 3, 8, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2160, 0, '2022-10-05 13:55:00', 1, 3, 9, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2161, 0, '2022-10-05 13:55:00', 1, 3, 10, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2162, 0, '2022-10-05 13:55:00', 1, 3, 11, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2163, 0, '2022-10-05 13:55:00', 1, 3, 12, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2164, 0, '2022-10-05 13:55:00', 1, 3, 13, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2165, 0, '2022-10-05 13:55:00', 1, 3, 14, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2166, 0, '2022-10-05 13:55:00', 1, 3, 15, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2167, 0, '2022-10-05 13:55:00', 1, 3, 16, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2168, 0, '2022-10-05 13:55:00', 1, 3, 17, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2169, 0, '2022-10-05 13:55:00', 1, 3, 18, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2170, 0, '2022-10-05 13:55:00', 1, 3, 19, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2171, 0, '2022-10-05 13:55:00', 1, 3, 20, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2172, 0, '2022-10-05 13:55:00', 1, 3, 21, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2173, 0, '2022-10-05 13:55:00', 1, 3, 22, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2174, 0, '2022-10-05 13:55:00', 1, 3, 23, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2175, 0, '2022-10-05 13:55:00', 1, 3, 24, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2176, 0, '2022-10-05 13:55:00', 1, 3, 25, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2177, 0, '2022-10-05 13:55:00', 1, 3, 26, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2178, 0, '2022-10-05 13:55:00', 1, 3, 27, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2179, 0, '2022-10-05 13:55:00', 1, 3, 28, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2180, 0, '2022-10-05 13:55:00', 1, 3, 29, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2181, 0, '2022-10-05 13:55:00', 1, 3, 30, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2182, 0, '2022-10-05 13:55:00', 1, 3, 31, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2183, 0, '2022-10-05 13:55:00', 1, 3, 32, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2184, 0, '2022-10-05 13:55:00', 1, 3, 33, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2185, 0, '2022-10-05 13:55:00', 1, 3, 34, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2186, 0, '2022-10-05 13:55:00', 1, 3, 35, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2187, 0, '2022-10-05 13:55:00', 1, 3, 36, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2188, 0, '2022-10-05 13:55:00', 1, 3, 37, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2189, 0, '2022-10-05 13:55:00', 1, 3, 38, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2190, 0, '2022-10-05 13:55:00', 1, 3, 39, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2191, 0, '2022-10-05 13:55:00', 1, 3, 40, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2192, 0, '2022-10-05 13:55:00', 1, 3, 41, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2193, 0, '2022-10-05 13:55:00', 1, 3, 42, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2194, 0, '2022-10-05 14:00:00', 1, 1, 0, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2195, 0, '2022-10-05 14:00:00', 1, 1, 1, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2196, 0, '2022-10-05 14:00:00', 1, 1, 2, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2197, 0, '2022-10-05 14:00:00', 1, 1, 3, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2198, 0, '2022-10-05 14:00:00', 1, 1, 4, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2199, 0, '2022-10-05 14:00:00', 1, 1, 5, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2200, 0, '2022-10-05 14:00:00', 1, 1, 6, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2201, 0, '2022-10-05 14:00:00', 1, 1, 7, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2202, 0, '2022-10-05 14:00:00', 1, 1, 8, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2203, 0, '2022-10-05 14:00:00', 1, 1, 9, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2204, 0, '2022-10-05 14:00:00', 1, 1, 10, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2205, 0, '2022-10-05 14:00:00', 1, 1, 11, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2206, 0, '2022-10-05 14:00:00', 1, 1, 12, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2207, 0, '2022-10-05 14:00:00', 1, 1, 13, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2208, 0, '2022-10-05 14:00:00', 1, 1, 14, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2209, 0, '2022-10-05 14:00:00', 1, 1, 15, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2210, 0, '2022-10-05 14:00:00', 1, 1, 16, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2211, 0, '2022-10-05 14:00:00', 1, 1, 17, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2212, 0, '2022-10-05 14:00:00', 1, 1, 18, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2213, 0, '2022-10-05 14:00:00', 1, 1, 19, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2214, 0, '2022-10-05 14:00:00', 1, 1, 20, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2215, 0, '2022-10-05 14:00:00', 1, 1, 21, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2216, 0, '2022-10-05 14:00:00', 1, 1, 22, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2217, 0, '2022-10-05 14:00:00', 1, 1, 23, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2218, 0, '2022-10-05 14:00:00', 1, 1, 24, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2219, 0, '2022-10-05 14:00:00', 1, 1, 25, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2220, 0, '2022-10-05 14:00:00', 1, 1, 26, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2221, 0, '2022-10-05 14:00:00', 1, 1, 27, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2222, 0, '2022-10-05 14:00:00', 1, 1, 28, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2223, 0, '2022-10-05 14:00:00', 1, 1, 29, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2224, 0, '2022-10-05 14:00:00', 1, 1, 30, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2225, 0, '2022-10-05 14:00:00', 1, 1, 31, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2226, 0, '2022-10-05 14:00:00', 1, 1, 32, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2227, 0, '2022-10-05 14:00:00', 1, 1, 33, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2228, 0, '2022-10-05 14:00:00', 1, 1, 34, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2229, 0, '2022-10-05 14:00:00', 1, 1, 35, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2230, 0, '2022-10-05 14:00:00', 1, 1, 36, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2231, 0, '2022-10-05 14:00:00', 1, 1, 37, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2232, 0, '2022-10-05 14:00:00', 1, 1, 38, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2233, 0, '2022-10-05 14:00:00', 1, 1, 39, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2234, 0, '2022-10-05 14:00:00', 1, 1, 40, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2235, 0, '2022-10-05 14:00:00', 1, 1, 41, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2236, 0, '2022-10-05 14:00:00', 1, 1, 42, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2237, 0, '2022-10-05 14:00:00', 1, 2, 0, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2238, 0, '2022-10-05 14:00:00', 1, 2, 1, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2239, 0, '2022-10-05 14:00:00', 1, 2, 2, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2240, 0, '2022-10-05 14:00:00', 1, 2, 3, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2241, 0, '2022-10-05 14:00:00', 1, 2, 4, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2242, 0, '2022-10-05 14:00:00', 1, 2, 5, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2243, 0, '2022-10-05 14:00:00', 1, 2, 6, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2244, 0, '2022-10-05 14:00:00', 1, 2, 7, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2245, 0, '2022-10-05 14:00:00', 1, 2, 8, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2246, 0, '2022-10-05 14:00:00', 1, 2, 9, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2247, 0, '2022-10-05 14:00:00', 1, 2, 10, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2248, 0, '2022-10-05 14:00:00', 1, 2, 11, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2249, 0, '2022-10-05 14:00:00', 1, 2, 12, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2250, 0, '2022-10-05 14:00:00', 1, 2, 13, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2251, 0, '2022-10-05 14:00:00', 1, 2, 14, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2252, 0, '2022-10-05 14:00:00', 1, 2, 15, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2253, 0, '2022-10-05 14:00:00', 1, 2, 16, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2254, 0, '2022-10-05 14:00:00', 1, 2, 17, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2255, 0, '2022-10-05 14:00:00', 1, 2, 18, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2256, 0, '2022-10-05 14:00:00', 1, 2, 19, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2257, 0, '2022-10-05 14:00:00', 1, 2, 20, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2258, 0, '2022-10-05 14:00:00', 1, 2, 21, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2259, 0, '2022-10-05 14:00:00', 1, 2, 22, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2260, 0, '2022-10-05 14:00:00', 1, 2, 23, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2261, 0, '2022-10-05 14:00:00', 1, 2, 24, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2262, 0, '2022-10-05 14:00:00', 1, 2, 25, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2263, 0, '2022-10-05 14:00:00', 1, 2, 26, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2264, 0, '2022-10-05 14:00:00', 1, 2, 27, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2265, 0, '2022-10-05 14:00:00', 1, 2, 28, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2266, 0, '2022-10-05 14:00:00', 1, 2, 29, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2267, 0, '2022-10-05 14:00:00', 1, 2, 30, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2268, 0, '2022-10-05 14:00:00', 1, 2, 31, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2269, 0, '2022-10-05 14:00:00', 1, 2, 32, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2270, 0, '2022-10-05 14:00:00', 1, 2, 33, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2271, 0, '2022-10-05 14:00:00', 1, 2, 34, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2272, 0, '2022-10-05 14:00:00', 1, 2, 35, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2273, 0, '2022-10-05 14:00:00', 1, 2, 36, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2274, 0, '2022-10-05 14:00:00', 1, 2, 37, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2275, 0, '2022-10-05 14:00:00', 1, 2, 38, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2276, 0, '2022-10-05 14:00:00', 1, 2, 39, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2277, 0, '2022-10-05 14:00:00', 1, 2, 40, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2278, 0, '2022-10-05 14:00:00', 1, 2, 41, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2279, 0, '2022-10-05 14:00:00', 1, 2, 42, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2280, 0, '2022-10-05 14:00:00', 1, 3, 0, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2281, 0, '2022-10-05 14:00:00', 1, 3, 1, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2282, 0, '2022-10-05 14:00:00', 1, 3, 2, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2283, 0, '2022-10-05 14:00:00', 1, 3, 3, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2284, 0, '2022-10-05 14:00:00', 1, 3, 4, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2285, 0, '2022-10-05 14:00:00', 1, 3, 5, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2286, 0, '2022-10-05 14:00:00', 1, 3, 6, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2287, 0, '2022-10-05 14:00:00', 1, 3, 7, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2288, 0, '2022-10-05 14:00:00', 1, 3, 8, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2289, 0, '2022-10-05 14:00:00', 1, 3, 9, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2290, 0, '2022-10-05 14:00:00', 1, 3, 10, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2291, 0, '2022-10-05 14:00:00', 1, 3, 11, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2292, 0, '2022-10-05 14:00:00', 1, 3, 12, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2293, 0, '2022-10-05 14:00:00', 1, 3, 13, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2294, 0, '2022-10-05 14:00:00', 1, 3, 14, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2295, 0, '2022-10-05 14:00:00', 1, 3, 15, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2296, 0, '2022-10-05 14:00:00', 1, 3, 16, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2297, 0, '2022-10-05 14:00:00', 1, 3, 17, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2298, 0, '2022-10-05 14:00:00', 1, 3, 18, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2299, 0, '2022-10-05 14:00:00', 1, 3, 19, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2300, 0, '2022-10-05 14:00:00', 1, 3, 20, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2301, 0, '2022-10-05 14:00:00', 1, 3, 21, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2302, 0, '2022-10-05 14:00:00', 1, 3, 22, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2303, 0, '2022-10-05 14:00:00', 1, 3, 23, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2304, 0, '2022-10-05 14:00:00', 1, 3, 24, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2305, 0, '2022-10-05 14:00:00', 1, 3, 25, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2306, 0, '2022-10-05 14:00:00', 1, 3, 26, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2307, 0, '2022-10-05 14:00:00', 1, 3, 27, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2308, 0, '2022-10-05 14:00:00', 1, 3, 28, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2309, 0, '2022-10-05 14:00:00', 1, 3, 29, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2310, 0, '2022-10-05 14:00:00', 1, 3, 30, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2311, 0, '2022-10-05 14:00:00', 1, 3, 31, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2312, 0, '2022-10-05 14:00:00', 1, 3, 32, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2313, 0, '2022-10-05 14:00:00', 1, 3, 33, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2314, 0, '2022-10-05 14:00:00', 1, 3, 34, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2315, 0, '2022-10-05 14:00:00', 1, 3, 35, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2316, 0, '2022-10-05 14:00:00', 1, 3, 36, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2317, 0, '2022-10-05 14:00:00', 1, 3, 37, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2318, 0, '2022-10-05 14:00:00', 1, 3, 38, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2319, 0, '2022-10-05 14:00:00', 1, 3, 39, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2320, 0, '2022-10-05 14:00:00', 1, 3, 40, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2321, 0, '2022-10-05 14:00:00', 1, 3, 41, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2322, 0, '2022-10-05 14:00:00', 1, 3, 42, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2323, 0, '2022-10-05 14:05:00', 1, 1, 0, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2324, 0, '2022-10-05 14:05:00', 1, 1, 1, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2325, 0, '2022-10-05 14:05:00', 1, 1, 2, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2326, 0, '2022-10-05 14:05:00', 1, 1, 3, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2327, 0, '2022-10-05 14:05:00', 1, 1, 4, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2328, 0, '2022-10-05 14:05:00', 1, 1, 5, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2329, 0, '2022-10-05 14:05:00', 1, 1, 6, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2330, 0, '2022-10-05 14:05:00', 1, 1, 7, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2331, 0, '2022-10-05 14:05:00', 1, 1, 8, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2332, 0, '2022-10-05 14:05:00', 1, 1, 9, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2333, 0, '2022-10-05 14:05:00', 1, 1, 10, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2334, 0, '2022-10-05 14:05:00', 1, 1, 11, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2335, 0, '2022-10-05 14:05:00', 1, 1, 12, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2336, 0, '2022-10-05 14:05:00', 1, 1, 13, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2337, 0, '2022-10-05 14:05:00', 1, 1, 14, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2338, 0, '2022-10-05 14:05:00', 1, 1, 15, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2339, 0, '2022-10-05 14:05:00', 1, 1, 16, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2340, 0, '2022-10-05 14:05:00', 1, 1, 17, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2341, 0, '2022-10-05 14:05:00', 1, 1, 18, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2342, 0, '2022-10-05 14:05:00', 1, 1, 19, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2343, 0, '2022-10-05 14:05:00', 1, 1, 20, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2344, 0, '2022-10-05 14:05:00', 1, 1, 21, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2345, 0, '2022-10-05 14:05:00', 1, 1, 22, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2346, 0, '2022-10-05 14:05:00', 1, 1, 23, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2347, 0, '2022-10-05 14:05:00', 1, 1, 24, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2348, 0, '2022-10-05 14:05:00', 1, 1, 25, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2349, 0, '2022-10-05 14:05:00', 1, 1, 26, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2350, 0, '2022-10-05 14:05:00', 1, 1, 27, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2351, 0, '2022-10-05 14:05:00', 1, 1, 28, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2352, 0, '2022-10-05 14:05:00', 1, 1, 29, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2353, 0, '2022-10-05 14:05:00', 1, 1, 30, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2354, 0, '2022-10-05 14:05:00', 1, 1, 31, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2355, 0, '2022-10-05 14:05:00', 1, 1, 32, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2356, 0, '2022-10-05 14:05:00', 1, 1, 33, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2357, 0, '2022-10-05 14:05:00', 1, 1, 34, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2358, 0, '2022-10-05 14:05:00', 1, 1, 35, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2359, 0, '2022-10-05 14:05:00', 1, 1, 36, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2360, 0, '2022-10-05 14:05:00', 1, 1, 37, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2361, 0, '2022-10-05 14:05:00', 1, 1, 38, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2362, 0, '2022-10-05 14:05:00', 1, 1, 39, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2363, 0, '2022-10-05 14:05:00', 1, 1, 40, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2364, 0, '2022-10-05 14:05:00', 1, 1, 41, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2365, 0, '2022-10-05 14:05:00', 1, 1, 42, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2366, 0, '2022-10-05 14:05:00', 1, 2, 0, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2367, 0, '2022-10-05 14:05:00', 1, 2, 1, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2368, 0, '2022-10-05 14:05:00', 1, 2, 2, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2369, 0, '2022-10-05 14:05:00', 1, 2, 3, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2370, 0, '2022-10-05 14:05:00', 1, 2, 4, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2371, 0, '2022-10-05 14:05:00', 1, 2, 5, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2372, 0, '2022-10-05 14:05:00', 1, 2, 6, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2373, 0, '2022-10-05 14:05:00', 1, 2, 7, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2374, 0, '2022-10-05 14:05:00', 1, 2, 8, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2375, 0, '2022-10-05 14:05:00', 1, 2, 9, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2376, 0, '2022-10-05 14:05:00', 1, 2, 10, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2377, 0, '2022-10-05 14:05:00', 1, 2, 11, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2378, 0, '2022-10-05 14:05:00', 1, 2, 12, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2379, 0, '2022-10-05 14:05:00', 1, 2, 13, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2380, 0, '2022-10-05 14:05:00', 1, 2, 14, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2381, 0, '2022-10-05 14:05:00', 1, 2, 15, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2382, 0, '2022-10-05 14:05:00', 1, 2, 16, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2383, 0, '2022-10-05 14:05:00', 1, 2, 17, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2384, 0, '2022-10-05 14:05:00', 1, 2, 18, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2385, 0, '2022-10-05 14:05:00', 1, 2, 19, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2386, 0, '2022-10-05 14:05:00', 1, 2, 20, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2387, 0, '2022-10-05 14:05:00', 1, 2, 21, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2388, 0, '2022-10-05 14:05:00', 1, 2, 22, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2389, 0, '2022-10-05 14:05:00', 1, 2, 23, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2390, 0, '2022-10-05 14:05:00', 1, 2, 24, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2391, 0, '2022-10-05 14:05:00', 1, 2, 25, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2392, 0, '2022-10-05 14:05:00', 1, 2, 26, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2393, 0, '2022-10-05 14:05:00', 1, 2, 27, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2394, 0, '2022-10-05 14:05:00', 1, 2, 28, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2395, 0, '2022-10-05 14:05:00', 1, 2, 29, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2396, 0, '2022-10-05 14:05:00', 1, 2, 30, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2397, 0, '2022-10-05 14:05:00', 1, 2, 31, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2398, 0, '2022-10-05 14:05:00', 1, 2, 32, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2399, 0, '2022-10-05 14:05:00', 1, 2, 33, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2400, 0, '2022-10-05 14:05:00', 1, 2, 34, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2401, 0, '2022-10-05 14:05:00', 1, 2, 35, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2402, 0, '2022-10-05 14:05:00', 1, 2, 36, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2403, 0, '2022-10-05 14:05:00', 1, 2, 37, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2404, 0, '2022-10-05 14:05:00', 1, 2, 38, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2405, 0, '2022-10-05 14:05:00', 1, 2, 39, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2406, 0, '2022-10-05 14:05:00', 1, 2, 40, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2407, 0, '2022-10-05 14:05:00', 1, 2, 41, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2408, 0, '2022-10-05 14:05:00', 1, 2, 42, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2409, 0, '2022-10-05 14:05:00', 1, 3, 0, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2410, 0, '2022-10-05 14:05:00', 1, 3, 1, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2411, 0, '2022-10-05 14:05:00', 1, 3, 2, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2412, 0, '2022-10-05 14:05:00', 1, 3, 3, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2413, 0, '2022-10-05 14:05:00', 1, 3, 4, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2414, 0, '2022-10-05 14:05:00', 1, 3, 5, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2415, 0, '2022-10-05 14:05:00', 1, 3, 6, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2416, 0, '2022-10-05 14:05:00', 1, 3, 7, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2417, 0, '2022-10-05 14:05:00', 1, 3, 8, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2418, 0, '2022-10-05 14:05:00', 1, 3, 9, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2419, 0, '2022-10-05 14:05:00', 1, 3, 10, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2420, 0, '2022-10-05 14:05:00', 1, 3, 11, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2421, 0, '2022-10-05 14:05:00', 1, 3, 12, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2422, 0, '2022-10-05 14:05:00', 1, 3, 13, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2423, 0, '2022-10-05 14:05:00', 1, 3, 14, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2424, 0, '2022-10-05 14:05:00', 1, 3, 15, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2425, 0, '2022-10-05 14:05:00', 1, 3, 16, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2426, 0, '2022-10-05 14:05:00', 1, 3, 17, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2427, 0, '2022-10-05 14:05:00', 1, 3, 18, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2428, 0, '2022-10-05 14:05:00', 1, 3, 19, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2429, 0, '2022-10-05 14:05:00', 1, 3, 20, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2430, 0, '2022-10-05 14:05:00', 1, 3, 21, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2431, 0, '2022-10-05 14:05:00', 1, 3, 22, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2432, 0, '2022-10-05 14:05:00', 1, 3, 23, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2433, 0, '2022-10-05 14:05:00', 1, 3, 24, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2434, 0, '2022-10-05 14:05:00', 1, 3, 25, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2435, 0, '2022-10-05 14:05:00', 1, 3, 26, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2436, 0, '2022-10-05 14:05:00', 1, 3, 27, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2437, 0, '2022-10-05 14:05:00', 1, 3, 28, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2438, 0, '2022-10-05 14:05:00', 1, 3, 29, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2439, 0, '2022-10-05 14:05:00', 1, 3, 30, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2440, 0, '2022-10-05 14:05:00', 1, 3, 31, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2441, 0, '2022-10-05 14:05:00', 1, 3, 32, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2442, 0, '2022-10-05 14:05:00', 1, 3, 33, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2443, 0, '2022-10-05 14:05:00', 1, 3, 34, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2444, 0, '2022-10-05 14:05:00', 1, 3, 35, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2445, 0, '2022-10-05 14:05:00', 1, 3, 36, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2446, 0, '2022-10-05 14:05:00', 1, 3, 37, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2447, 0, '2022-10-05 14:05:00', 1, 3, 38, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2448, 0, '2022-10-05 14:05:00', 1, 3, 39, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2449, 0, '2022-10-05 14:05:00', 1, 3, 40, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2450, 0, '2022-10-05 14:05:00', 1, 3, 41, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2451, 0, '2022-10-05 14:05:00', 1, 3, 42, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2452, 0, '2022-10-05 14:10:00', 1, 1, 0, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2453, 0, '2022-10-05 14:10:00', 1, 1, 1, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2454, 0, '2022-10-05 14:10:00', 1, 1, 2, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2455, 0, '2022-10-05 14:10:00', 1, 1, 3, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2456, 0, '2022-10-05 14:10:00', 1, 1, 4, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2457, 0, '2022-10-05 14:10:00', 1, 1, 5, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2458, 0, '2022-10-05 14:10:00', 1, 1, 6, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2459, 0, '2022-10-05 14:10:00', 1, 1, 7, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2460, 0, '2022-10-05 14:10:00', 1, 1, 8, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2461, 0, '2022-10-05 14:10:00', 1, 1, 9, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2462, 0, '2022-10-05 14:10:00', 1, 1, 10, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2463, 0, '2022-10-05 14:10:00', 1, 1, 11, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2464, 0, '2022-10-05 14:10:00', 1, 1, 12, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2465, 0, '2022-10-05 14:10:00', 1, 1, 13, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2466, 0, '2022-10-05 14:10:00', 1, 1, 14, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2467, 0, '2022-10-05 14:10:00', 1, 1, 15, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2468, 0, '2022-10-05 14:10:00', 1, 1, 16, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2469, 0, '2022-10-05 14:10:00', 1, 1, 17, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2470, 0, '2022-10-05 14:10:00', 1, 1, 18, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2471, 0, '2022-10-05 14:10:00', 1, 1, 19, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2472, 0, '2022-10-05 14:10:00', 1, 1, 20, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2473, 0, '2022-10-05 14:10:00', 1, 1, 21, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2474, 0, '2022-10-05 14:10:00', 1, 1, 22, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2475, 0, '2022-10-05 14:10:00', 1, 1, 23, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2476, 0, '2022-10-05 14:10:00', 1, 1, 24, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2477, 0, '2022-10-05 14:10:00', 1, 1, 25, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2478, 0, '2022-10-05 14:10:00', 1, 1, 26, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2479, 0, '2022-10-05 14:10:00', 1, 1, 27, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2480, 0, '2022-10-05 14:10:00', 1, 1, 28, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2481, 0, '2022-10-05 14:10:00', 1, 1, 29, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2482, 0, '2022-10-05 14:10:00', 1, 1, 30, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2483, 0, '2022-10-05 14:10:00', 1, 1, 31, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2484, 0, '2022-10-05 14:10:00', 1, 1, 32, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2485, 0, '2022-10-05 14:10:00', 1, 1, 33, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2486, 0, '2022-10-05 14:10:00', 1, 1, 34, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2487, 0, '2022-10-05 14:10:00', 1, 1, 35, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2488, 0, '2022-10-05 14:10:00', 1, 1, 36, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2489, 0, '2022-10-05 14:10:00', 1, 1, 37, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2490, 0, '2022-10-05 14:10:00', 1, 1, 38, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2491, 0, '2022-10-05 14:10:00', 1, 1, 39, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2492, 0, '2022-10-05 14:10:00', 1, 1, 40, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2493, 0, '2022-10-05 14:10:00', 1, 1, 41, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2494, 0, '2022-10-05 14:10:00', 1, 1, 42, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2495, 0, '2022-10-05 14:10:00', 1, 2, 0, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2496, 0, '2022-10-05 14:10:00', 1, 2, 1, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2497, 0, '2022-10-05 14:10:00', 1, 2, 2, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2498, 0, '2022-10-05 14:10:00', 1, 2, 3, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2499, 0, '2022-10-05 14:10:00', 1, 2, 4, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2500, 0, '2022-10-05 14:10:00', 1, 2, 5, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2501, 0, '2022-10-05 14:10:00', 1, 2, 6, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2502, 0, '2022-10-05 14:10:00', 1, 2, 7, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2503, 0, '2022-10-05 14:10:00', 1, 2, 8, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2504, 0, '2022-10-05 14:10:00', 1, 2, 9, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2505, 0, '2022-10-05 14:10:00', 1, 2, 10, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2506, 0, '2022-10-05 14:10:00', 1, 2, 11, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2507, 0, '2022-10-05 14:10:00', 1, 2, 12, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2508, 0, '2022-10-05 14:10:00', 1, 2, 13, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2509, 0, '2022-10-05 14:10:00', 1, 2, 14, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2510, 0, '2022-10-05 14:10:00', 1, 2, 15, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2511, 0, '2022-10-05 14:10:00', 1, 2, 16, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2512, 0, '2022-10-05 14:10:00', 1, 2, 17, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2513, 0, '2022-10-05 14:10:00', 1, 2, 18, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2514, 0, '2022-10-05 14:10:00', 1, 2, 19, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2515, 0, '2022-10-05 14:10:00', 1, 2, 20, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2516, 0, '2022-10-05 14:10:00', 1, 2, 21, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2517, 0, '2022-10-05 14:10:00', 1, 2, 22, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2518, 0, '2022-10-05 14:10:00', 1, 2, 23, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2519, 0, '2022-10-05 14:10:00', 1, 2, 24, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2520, 0, '2022-10-05 14:10:00', 1, 2, 25, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2521, 0, '2022-10-05 14:10:00', 1, 2, 26, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2522, 0, '2022-10-05 14:10:00', 1, 2, 27, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2523, 0, '2022-10-05 14:10:00', 1, 2, 28, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2524, 0, '2022-10-05 14:10:00', 1, 2, 29, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2525, 0, '2022-10-05 14:10:00', 1, 2, 30, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2526, 0, '2022-10-05 14:10:00', 1, 2, 31, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2527, 0, '2022-10-05 14:10:00', 1, 2, 32, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2528, 0, '2022-10-05 14:10:00', 1, 2, 33, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2529, 0, '2022-10-05 14:10:00', 1, 2, 34, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2530, 0, '2022-10-05 14:10:00', 1, 2, 35, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2531, 0, '2022-10-05 14:10:00', 1, 2, 36, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2532, 0, '2022-10-05 14:10:00', 1, 2, 37, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2533, 0, '2022-10-05 14:10:00', 1, 2, 38, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2534, 0, '2022-10-05 14:10:00', 1, 2, 39, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2535, 0, '2022-10-05 14:10:00', 1, 2, 40, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2536, 0, '2022-10-05 14:10:00', 1, 2, 41, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2537, 0, '2022-10-05 14:10:00', 1, 2, 42, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2538, 0, '2022-10-05 14:10:00', 1, 3, 0, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2539, 0, '2022-10-05 14:10:00', 1, 3, 1, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2540, 0, '2022-10-05 14:10:00', 1, 3, 2, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2541, 0, '2022-10-05 14:10:00', 1, 3, 3, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2542, 0, '2022-10-05 14:10:00', 1, 3, 4, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2543, 0, '2022-10-05 14:10:00', 1, 3, 5, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2544, 0, '2022-10-05 14:10:00', 1, 3, 6, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2545, 0, '2022-10-05 14:10:00', 1, 3, 7, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2546, 0, '2022-10-05 14:10:00', 1, 3, 8, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2547, 0, '2022-10-05 14:10:00', 1, 3, 9, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2548, 0, '2022-10-05 14:10:00', 1, 3, 10, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2549, 0, '2022-10-05 14:10:00', 1, 3, 11, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2550, 0, '2022-10-05 14:10:00', 1, 3, 12, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2551, 0, '2022-10-05 14:10:00', 1, 3, 13, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2552, 0, '2022-10-05 14:10:00', 1, 3, 14, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2553, 0, '2022-10-05 14:10:00', 1, 3, 15, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2554, 0, '2022-10-05 14:10:00', 1, 3, 16, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2555, 0, '2022-10-05 14:10:00', 1, 3, 17, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2556, 0, '2022-10-05 14:10:00', 1, 3, 18, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2557, 0, '2022-10-05 14:10:00', 1, 3, 19, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2558, 0, '2022-10-05 14:10:00', 1, 3, 20, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2559, 0, '2022-10-05 14:10:00', 1, 3, 21, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2560, 0, '2022-10-05 14:10:00', 1, 3, 22, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2561, 0, '2022-10-05 14:10:00', 1, 3, 23, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2562, 0, '2022-10-05 14:10:00', 1, 3, 24, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2563, 0, '2022-10-05 14:10:00', 1, 3, 25, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2564, 0, '2022-10-05 14:10:00', 1, 3, 26, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2565, 0, '2022-10-05 14:10:00', 1, 3, 27, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2566, 0, '2022-10-05 14:10:00', 1, 3, 28, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2567, 0, '2022-10-05 14:10:00', 1, 3, 29, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2568, 0, '2022-10-05 14:10:00', 1, 3, 30, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2569, 0, '2022-10-05 14:10:00', 1, 3, 31, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2570, 0, '2022-10-05 14:10:00', 1, 3, 32, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2571, 0, '2022-10-05 14:10:00', 1, 3, 33, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2572, 0, '2022-10-05 14:10:00', 1, 3, 34, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2573, 0, '2022-10-05 14:10:00', 1, 3, 35, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2574, 0, '2022-10-05 14:10:00', 1, 3, 36, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2575, 0, '2022-10-05 14:10:00', 1, 3, 37, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2576, 0, '2022-10-05 14:10:00', 1, 3, 38, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2577, 0, '2022-10-05 14:10:00', 1, 3, 39, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2578, 0, '2022-10-05 14:10:00', 1, 3, 40, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2579, 0, '2022-10-05 14:10:00', 1, 3, 41, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2580, 0, '2022-10-05 14:10:00', 1, 3, 42, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2581, 0, '2022-10-05 14:15:00', 1, 1, 0, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2582, 0, '2022-10-05 14:15:00', 1, 1, 1, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2583, 0, '2022-10-05 14:15:00', 1, 1, 2, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2584, 0, '2022-10-05 14:15:00', 1, 1, 3, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2585, 0, '2022-10-05 14:15:00', 1, 1, 4, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2586, 0, '2022-10-05 14:15:00', 1, 1, 5, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2587, 0, '2022-10-05 14:15:00', 1, 1, 6, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2588, 0, '2022-10-05 14:15:00', 1, 1, 7, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2589, 0, '2022-10-05 14:15:00', 1, 1, 8, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2590, 0, '2022-10-05 14:15:00', 1, 1, 9, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2591, 0, '2022-10-05 14:15:00', 1, 1, 10, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2592, 0, '2022-10-05 14:15:00', 1, 1, 11, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2593, 0, '2022-10-05 14:15:00', 1, 1, 12, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2594, 0, '2022-10-05 14:15:00', 1, 1, 13, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2595, 0, '2022-10-05 14:15:00', 1, 1, 14, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2596, 0, '2022-10-05 14:15:00', 1, 1, 15, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2597, 0, '2022-10-05 14:15:00', 1, 1, 16, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2598, 0, '2022-10-05 14:15:00', 1, 1, 17, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2599, 0, '2022-10-05 14:15:00', 1, 1, 18, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2600, 0, '2022-10-05 14:15:00', 1, 1, 19, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2601, 0, '2022-10-05 14:15:00', 1, 1, 20, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2602, 0, '2022-10-05 14:15:00', 1, 1, 21, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2603, 0, '2022-10-05 14:15:00', 1, 1, 22, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2604, 0, '2022-10-05 14:15:00', 1, 1, 23, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2605, 0, '2022-10-05 14:15:00', 1, 1, 24, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2606, 0, '2022-10-05 14:15:00', 1, 1, 25, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2607, 0, '2022-10-05 14:15:00', 1, 1, 26, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2608, 0, '2022-10-05 14:15:00', 1, 1, 27, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2609, 0, '2022-10-05 14:15:00', 1, 1, 28, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2610, 0, '2022-10-05 14:15:00', 1, 1, 29, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2611, 0, '2022-10-05 14:15:00', 1, 1, 30, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2612, 0, '2022-10-05 14:15:00', 1, 1, 31, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2613, 0, '2022-10-05 14:15:00', 1, 1, 32, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2614, 0, '2022-10-05 14:15:00', 1, 1, 33, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2615, 0, '2022-10-05 14:15:00', 1, 1, 34, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2616, 0, '2022-10-05 14:15:00', 1, 1, 35, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2617, 0, '2022-10-05 14:15:00', 1, 1, 36, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2618, 0, '2022-10-05 14:15:00', 1, 1, 37, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2619, 0, '2022-10-05 14:15:00', 1, 1, 38, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2620, 0, '2022-10-05 14:15:00', 1, 1, 39, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2621, 0, '2022-10-05 14:15:00', 1, 1, 40, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2622, 0, '2022-10-05 14:15:00', 1, 1, 41, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2623, 0, '2022-10-05 14:15:00', 1, 1, 42, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2624, 0, '2022-10-05 14:15:00', 1, 2, 0, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2625, 0, '2022-10-05 14:15:00', 1, 2, 1, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2626, 0, '2022-10-05 14:15:00', 1, 2, 2, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2627, 0, '2022-10-05 14:15:00', 1, 2, 3, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2628, 0, '2022-10-05 14:15:00', 1, 2, 4, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2629, 0, '2022-10-05 14:15:00', 1, 2, 5, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2630, 0, '2022-10-05 14:15:00', 1, 2, 6, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2631, 0, '2022-10-05 14:15:00', 1, 2, 7, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2632, 0, '2022-10-05 14:15:00', 1, 2, 8, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2633, 0, '2022-10-05 14:15:00', 1, 2, 9, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2634, 0, '2022-10-05 14:15:00', 1, 2, 10, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2635, 0, '2022-10-05 14:15:00', 1, 2, 11, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2636, 0, '2022-10-05 14:15:00', 1, 2, 12, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2637, 0, '2022-10-05 14:15:00', 1, 2, 13, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2638, 0, '2022-10-05 14:15:00', 1, 2, 14, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2639, 0, '2022-10-05 14:15:00', 1, 2, 15, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2640, 0, '2022-10-05 14:15:00', 1, 2, 16, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2641, 0, '2022-10-05 14:15:00', 1, 2, 17, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2642, 0, '2022-10-05 14:15:00', 1, 2, 18, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2643, 0, '2022-10-05 14:15:00', 1, 2, 19, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2644, 0, '2022-10-05 14:15:00', 1, 2, 20, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2645, 0, '2022-10-05 14:15:00', 1, 2, 21, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2646, 0, '2022-10-05 14:15:00', 1, 2, 22, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2647, 0, '2022-10-05 14:15:00', 1, 2, 23, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2648, 0, '2022-10-05 14:15:00', 1, 2, 24, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2649, 0, '2022-10-05 14:15:00', 1, 2, 25, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2650, 0, '2022-10-05 14:15:00', 1, 2, 26, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2651, 0, '2022-10-05 14:15:00', 1, 2, 27, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2652, 0, '2022-10-05 14:15:00', 1, 2, 28, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2653, 0, '2022-10-05 14:15:00', 1, 2, 29, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2654, 0, '2022-10-05 14:15:00', 1, 2, 30, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2655, 0, '2022-10-05 14:15:00', 1, 2, 31, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2656, 0, '2022-10-05 14:15:00', 1, 2, 32, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2657, 0, '2022-10-05 14:15:00', 1, 2, 33, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2658, 0, '2022-10-05 14:15:00', 1, 2, 34, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2659, 0, '2022-10-05 14:15:00', 1, 2, 35, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2660, 0, '2022-10-05 14:15:00', 1, 2, 36, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2661, 0, '2022-10-05 14:15:00', 1, 2, 37, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2662, 0, '2022-10-05 14:15:00', 1, 2, 38, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2663, 0, '2022-10-05 14:15:00', 1, 2, 39, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2664, 0, '2022-10-05 14:15:00', 1, 2, 40, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2665, 0, '2022-10-05 14:15:00', 1, 2, 41, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2666, 0, '2022-10-05 14:15:00', 1, 2, 42, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2667, 0, '2022-10-05 14:15:00', 1, 3, 0, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2668, 0, '2022-10-05 14:15:00', 1, 3, 1, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2669, 0, '2022-10-05 14:15:00', 1, 3, 2, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2670, 0, '2022-10-05 14:15:00', 1, 3, 3, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2671, 0, '2022-10-05 14:15:00', 1, 3, 4, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2672, 0, '2022-10-05 14:15:00', 1, 3, 5, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2673, 0, '2022-10-05 14:15:00', 1, 3, 6, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2674, 0, '2022-10-05 14:15:00', 1, 3, 7, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2675, 0, '2022-10-05 14:15:00', 1, 3, 8, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2676, 0, '2022-10-05 14:15:00', 1, 3, 9, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2677, 0, '2022-10-05 14:15:00', 1, 3, 10, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2678, 0, '2022-10-05 14:15:00', 1, 3, 11, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2679, 0, '2022-10-05 14:15:00', 1, 3, 12, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2680, 0, '2022-10-05 14:15:00', 1, 3, 13, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2681, 0, '2022-10-05 14:15:00', 1, 3, 14, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2682, 0, '2022-10-05 14:15:00', 1, 3, 15, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2683, 0, '2022-10-05 14:15:00', 1, 3, 16, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2684, 0, '2022-10-05 14:15:00', 1, 3, 17, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2685, 0, '2022-10-05 14:15:00', 1, 3, 18, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2686, 0, '2022-10-05 14:15:00', 1, 3, 19, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2687, 0, '2022-10-05 14:15:00', 1, 3, 20, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2688, 0, '2022-10-05 14:15:00', 1, 3, 21, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2689, 0, '2022-10-05 14:15:00', 1, 3, 22, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2690, 0, '2022-10-05 14:15:00', 1, 3, 23, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2691, 0, '2022-10-05 14:15:00', 1, 3, 24, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2692, 0, '2022-10-05 14:15:00', 1, 3, 25, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2693, 0, '2022-10-05 14:15:00', 1, 3, 26, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2694, 0, '2022-10-05 14:15:00', 1, 3, 27, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2695, 0, '2022-10-05 14:15:00', 1, 3, 28, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2696, 0, '2022-10-05 14:15:00', 1, 3, 29, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2697, 0, '2022-10-05 14:15:00', 1, 3, 30, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2698, 0, '2022-10-05 14:15:00', 1, 3, 31, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2699, 0, '2022-10-05 14:15:00', 1, 3, 32, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2700, 0, '2022-10-05 14:15:00', 1, 3, 33, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2701, 0, '2022-10-05 14:15:00', 1, 3, 34, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2702, 0, '2022-10-05 14:15:00', 1, 3, 35, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2703, 0, '2022-10-05 14:15:00', 1, 3, 36, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2704, 0, '2022-10-05 14:15:00', 1, 3, 37, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2705, 0, '2022-10-05 14:15:00', 1, 3, 38, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2706, 0, '2022-10-05 14:15:00', 1, 3, 39, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2707, 0, '2022-10-05 14:15:00', 1, 3, 40, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2708, 0, '2022-10-05 14:15:00', 1, 3, 41, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2709, 0, '2022-10-05 14:15:00', 1, 3, 42, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2710, 0, '2022-10-05 14:20:00', 1, 1, 0, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2711, 0, '2022-10-05 14:20:00', 1, 1, 1, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2712, 0, '2022-10-05 14:20:00', 1, 1, 2, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2713, 0, '2022-10-05 14:20:00', 1, 1, 3, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2714, 0, '2022-10-05 14:20:00', 1, 1, 4, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2715, 0, '2022-10-05 14:20:00', 1, 1, 5, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2716, 0, '2022-10-05 14:20:00', 1, 1, 6, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2717, 0, '2022-10-05 14:20:00', 1, 1, 7, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2718, 0, '2022-10-05 14:20:00', 1, 1, 8, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2719, 0, '2022-10-05 14:20:00', 1, 1, 9, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2720, 0, '2022-10-05 14:20:00', 1, 1, 10, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2721, 0, '2022-10-05 14:20:00', 1, 1, 11, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2722, 0, '2022-10-05 14:20:00', 1, 1, 12, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2723, 0, '2022-10-05 14:20:00', 1, 1, 13, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2724, 0, '2022-10-05 14:20:00', 1, 1, 14, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2725, 0, '2022-10-05 14:20:00', 1, 1, 15, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2726, 0, '2022-10-05 14:20:00', 1, 1, 16, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2727, 0, '2022-10-05 14:20:00', 1, 1, 17, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2728, 0, '2022-10-05 14:20:00', 1, 1, 18, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2729, 0, '2022-10-05 14:20:00', 1, 1, 19, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2730, 0, '2022-10-05 14:20:00', 1, 1, 20, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2731, 0, '2022-10-05 14:20:00', 1, 1, 21, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2732, 0, '2022-10-05 14:20:00', 1, 1, 22, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2733, 0, '2022-10-05 14:20:00', 1, 1, 23, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2734, 0, '2022-10-05 14:20:00', 1, 1, 24, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2735, 0, '2022-10-05 14:20:00', 1, 1, 25, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2736, 0, '2022-10-05 14:20:00', 1, 1, 26, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2737, 0, '2022-10-05 14:20:00', 1, 1, 27, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2738, 0, '2022-10-05 14:20:00', 1, 1, 28, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2739, 0, '2022-10-05 14:20:00', 1, 1, 29, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2740, 0, '2022-10-05 14:20:00', 1, 1, 30, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2741, 0, '2022-10-05 14:20:00', 1, 1, 31, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2742, 0, '2022-10-05 14:20:00', 1, 1, 32, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2743, 0, '2022-10-05 14:20:00', 1, 1, 33, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2744, 0, '2022-10-05 14:20:00', 1, 1, 34, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2745, 0, '2022-10-05 14:20:00', 1, 1, 35, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2746, 0, '2022-10-05 14:20:00', 1, 1, 36, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2747, 0, '2022-10-05 14:20:00', 1, 1, 37, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2748, 0, '2022-10-05 14:20:00', 1, 1, 38, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2749, 0, '2022-10-05 14:20:00', 1, 1, 39, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2750, 0, '2022-10-05 14:20:00', 1, 1, 40, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2751, 0, '2022-10-05 14:20:00', 1, 1, 41, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2752, 0, '2022-10-05 14:20:00', 1, 1, 42, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2753, 0, '2022-10-05 14:20:00', 1, 2, 0, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2754, 0, '2022-10-05 14:20:00', 1, 2, 1, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2755, 0, '2022-10-05 14:20:00', 1, 2, 2, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2756, 0, '2022-10-05 14:20:00', 1, 2, 3, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2757, 0, '2022-10-05 14:20:00', 1, 2, 4, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2758, 0, '2022-10-05 14:20:00', 1, 2, 5, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2759, 0, '2022-10-05 14:20:00', 1, 2, 6, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2760, 0, '2022-10-05 14:20:00', 1, 2, 7, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2761, 0, '2022-10-05 14:20:00', 1, 2, 8, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2762, 0, '2022-10-05 14:20:00', 1, 2, 9, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2763, 0, '2022-10-05 14:20:00', 1, 2, 10, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2764, 0, '2022-10-05 14:20:00', 1, 2, 11, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2765, 0, '2022-10-05 14:20:00', 1, 2, 12, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2766, 0, '2022-10-05 14:20:00', 1, 2, 13, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2767, 0, '2022-10-05 14:20:00', 1, 2, 14, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2768, 0, '2022-10-05 14:20:00', 1, 2, 15, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2769, 0, '2022-10-05 14:20:00', 1, 2, 16, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2770, 0, '2022-10-05 14:20:00', 1, 2, 17, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2771, 0, '2022-10-05 14:20:00', 1, 2, 18, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2772, 0, '2022-10-05 14:20:00', 1, 2, 19, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2773, 0, '2022-10-05 14:20:00', 1, 2, 20, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2774, 0, '2022-10-05 14:20:00', 1, 2, 21, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2775, 0, '2022-10-05 14:20:00', 1, 2, 22, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2776, 0, '2022-10-05 14:20:00', 1, 2, 23, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2777, 0, '2022-10-05 14:20:00', 1, 2, 24, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2778, 0, '2022-10-05 14:20:00', 1, 2, 25, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2779, 0, '2022-10-05 14:20:00', 1, 2, 26, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2780, 0, '2022-10-05 14:20:00', 1, 2, 27, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2781, 0, '2022-10-05 14:20:00', 1, 2, 28, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2782, 0, '2022-10-05 14:20:00', 1, 2, 29, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2783, 0, '2022-10-05 14:20:00', 1, 2, 30, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2784, 0, '2022-10-05 14:20:00', 1, 2, 31, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2785, 0, '2022-10-05 14:20:00', 1, 2, 32, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2786, 0, '2022-10-05 14:20:00', 1, 2, 33, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2787, 0, '2022-10-05 14:20:00', 1, 2, 34, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2788, 0, '2022-10-05 14:20:00', 1, 2, 35, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2789, 0, '2022-10-05 14:20:00', 1, 2, 36, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2790, 0, '2022-10-05 14:20:00', 1, 2, 37, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2791, 0, '2022-10-05 14:20:00', 1, 2, 38, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2792, 0, '2022-10-05 14:20:00', 1, 2, 39, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2793, 0, '2022-10-05 14:20:00', 1, 2, 40, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2794, 0, '2022-10-05 14:20:00', 1, 2, 41, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2795, 0, '2022-10-05 14:20:00', 1, 2, 42, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2796, 0, '2022-10-05 14:20:00', 1, 3, 0, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2797, 0, '2022-10-05 14:20:00', 1, 3, 1, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2798, 0, '2022-10-05 14:20:00', 1, 3, 2, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2799, 0, '2022-10-05 14:20:00', 1, 3, 3, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2800, 0, '2022-10-05 14:20:00', 1, 3, 4, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2801, 0, '2022-10-05 14:20:00', 1, 3, 5, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2802, 0, '2022-10-05 14:20:00', 1, 3, 6, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2803, 0, '2022-10-05 14:20:00', 1, 3, 7, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2804, 0, '2022-10-05 14:20:00', 1, 3, 8, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2805, 0, '2022-10-05 14:20:00', 1, 3, 9, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2806, 0, '2022-10-05 14:20:00', 1, 3, 10, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2807, 0, '2022-10-05 14:20:00', 1, 3, 11, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2808, 0, '2022-10-05 14:20:00', 1, 3, 12, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2809, 0, '2022-10-05 14:20:00', 1, 3, 13, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2810, 0, '2022-10-05 14:20:00', 1, 3, 14, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2811, 0, '2022-10-05 14:20:00', 1, 3, 15, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2812, 0, '2022-10-05 14:20:00', 1, 3, 16, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2813, 0, '2022-10-05 14:20:00', 1, 3, 17, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2814, 0, '2022-10-05 14:20:00', 1, 3, 18, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2815, 0, '2022-10-05 14:20:00', 1, 3, 19, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2816, 0, '2022-10-05 14:20:00', 1, 3, 20, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2817, 0, '2022-10-05 14:20:00', 1, 3, 21, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2818, 0, '2022-10-05 14:20:00', 1, 3, 22, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2819, 0, '2022-10-05 14:20:00', 1, 3, 23, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2820, 0, '2022-10-05 14:20:00', 1, 3, 24, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2821, 0, '2022-10-05 14:20:00', 1, 3, 25, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2822, 0, '2022-10-05 14:20:00', 1, 3, 26, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2823, 0, '2022-10-05 14:20:00', 1, 3, 27, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2824, 0, '2022-10-05 14:20:00', 1, 3, 28, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2825, 0, '2022-10-05 14:20:00', 1, 3, 29, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2826, 0, '2022-10-05 14:20:00', 1, 3, 30, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2827, 0, '2022-10-05 14:20:00', 1, 3, 31, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2828, 0, '2022-10-05 14:20:00', 1, 3, 32, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2829, 0, '2022-10-05 14:20:00', 1, 3, 33, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2830, 0, '2022-10-05 14:20:00', 1, 3, 34, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2831, 0, '2022-10-05 14:20:00', 1, 3, 35, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2832, 0, '2022-10-05 14:20:00', 1, 3, 36, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2833, 0, '2022-10-05 14:20:00', 1, 3, 37, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2834, 0, '2022-10-05 14:20:00', 1, 3, 38, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2835, 0, '2022-10-05 14:20:00', 1, 3, 39, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2836, 0, '2022-10-05 14:20:00', 1, 3, 40, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2837, 0, '2022-10-05 14:20:00', 1, 3, 41, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2838, 0, '2022-10-05 14:20:00', 1, 3, 42, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2839, 0, '2022-10-05 14:25:00', 1, 1, 0, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2840, 0, '2022-10-05 14:25:00', 1, 1, 1, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2841, 0, '2022-10-05 14:25:00', 1, 1, 2, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2842, 0, '2022-10-05 14:25:00', 1, 1, 3, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2843, 0, '2022-10-05 14:25:00', 1, 1, 4, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2844, 0, '2022-10-05 14:25:00', 1, 1, 5, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2845, 0, '2022-10-05 14:25:00', 1, 1, 6, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2846, 0, '2022-10-05 14:25:00', 1, 1, 7, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2847, 0, '2022-10-05 14:25:00', 1, 1, 8, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2848, 0, '2022-10-05 14:25:00', 1, 1, 9, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2849, 0, '2022-10-05 14:25:00', 1, 1, 10, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2850, 0, '2022-10-05 14:25:00', 1, 1, 11, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2851, 0, '2022-10-05 14:25:00', 1, 1, 12, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2852, 0, '2022-10-05 14:25:00', 1, 1, 13, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2853, 0, '2022-10-05 14:25:00', 1, 1, 14, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2854, 0, '2022-10-05 14:25:00', 1, 1, 15, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2855, 0, '2022-10-05 14:25:00', 1, 1, 16, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2856, 0, '2022-10-05 14:25:00', 1, 1, 17, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2857, 0, '2022-10-05 14:25:00', 1, 1, 18, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2858, 0, '2022-10-05 14:25:00', 1, 1, 19, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2859, 0, '2022-10-05 14:25:00', 1, 1, 20, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2860, 0, '2022-10-05 14:25:00', 1, 1, 21, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2861, 0, '2022-10-05 14:25:00', 1, 1, 22, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2862, 0, '2022-10-05 14:25:00', 1, 1, 23, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2863, 0, '2022-10-05 14:25:00', 1, 1, 24, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2864, 0, '2022-10-05 14:25:00', 1, 1, 25, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2865, 0, '2022-10-05 14:25:00', 1, 1, 26, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2866, 0, '2022-10-05 14:25:00', 1, 1, 27, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2867, 0, '2022-10-05 14:25:00', 1, 1, 28, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2868, 0, '2022-10-05 14:25:00', 1, 1, 29, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2869, 0, '2022-10-05 14:25:00', 1, 1, 30, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2870, 0, '2022-10-05 14:25:00', 1, 1, 31, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2871, 0, '2022-10-05 14:25:00', 1, 1, 32, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2872, 0, '2022-10-05 14:25:00', 1, 1, 33, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2873, 0, '2022-10-05 14:25:00', 1, 1, 34, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2874, 0, '2022-10-05 14:25:00', 1, 1, 35, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2875, 0, '2022-10-05 14:25:00', 1, 1, 36, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2876, 0, '2022-10-05 14:25:00', 1, 1, 37, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2877, 0, '2022-10-05 14:25:00', 1, 1, 38, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2878, 0, '2022-10-05 14:25:00', 1, 1, 39, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2879, 0, '2022-10-05 14:25:00', 1, 1, 40, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2880, 0, '2022-10-05 14:25:00', 1, 1, 41, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2881, 0, '2022-10-05 14:25:00', 1, 1, 42, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2882, 0, '2022-10-05 14:25:00', 1, 2, 0, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2883, 0, '2022-10-05 14:25:00', 1, 2, 1, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2884, 0, '2022-10-05 14:25:00', 1, 2, 2, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2885, 0, '2022-10-05 14:25:00', 1, 2, 3, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2886, 0, '2022-10-05 14:25:00', 1, 2, 4, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2887, 0, '2022-10-05 14:25:00', 1, 2, 5, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2888, 0, '2022-10-05 14:25:00', 1, 2, 6, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2889, 0, '2022-10-05 14:25:00', 1, 2, 7, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2890, 0, '2022-10-05 14:25:00', 1, 2, 8, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2891, 0, '2022-10-05 14:25:00', 1, 2, 9, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2892, 0, '2022-10-05 14:25:00', 1, 2, 10, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2893, 0, '2022-10-05 14:25:00', 1, 2, 11, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2894, 0, '2022-10-05 14:25:00', 1, 2, 12, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2895, 0, '2022-10-05 14:25:00', 1, 2, 13, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2896, 0, '2022-10-05 14:25:00', 1, 2, 14, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2897, 0, '2022-10-05 14:25:00', 1, 2, 15, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2898, 0, '2022-10-05 14:25:00', 1, 2, 16, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2899, 0, '2022-10-05 14:25:00', 1, 2, 17, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2900, 0, '2022-10-05 14:25:00', 1, 2, 18, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2901, 0, '2022-10-05 14:25:00', 1, 2, 19, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2902, 0, '2022-10-05 14:25:00', 1, 2, 20, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2903, 0, '2022-10-05 14:25:00', 1, 2, 21, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2904, 0, '2022-10-05 14:25:00', 1, 2, 22, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2905, 0, '2022-10-05 14:25:00', 1, 2, 23, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2906, 0, '2022-10-05 14:25:00', 1, 2, 24, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2907, 0, '2022-10-05 14:25:00', 1, 2, 25, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2908, 0, '2022-10-05 14:25:00', 1, 2, 26, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2909, 0, '2022-10-05 14:25:00', 1, 2, 27, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2910, 0, '2022-10-05 14:25:00', 1, 2, 28, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2911, 0, '2022-10-05 14:25:00', 1, 2, 29, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2912, 0, '2022-10-05 14:25:00', 1, 2, 30, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2913, 0, '2022-10-05 14:25:00', 1, 2, 31, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2914, 0, '2022-10-05 14:25:00', 1, 2, 32, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2915, 0, '2022-10-05 14:25:00', 1, 2, 33, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2916, 0, '2022-10-05 14:25:00', 1, 2, 34, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2917, 0, '2022-10-05 14:25:00', 1, 2, 35, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2918, 0, '2022-10-05 14:25:00', 1, 2, 36, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2919, 0, '2022-10-05 14:25:00', 1, 2, 37, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2920, 0, '2022-10-05 14:25:00', 1, 2, 38, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2921, 0, '2022-10-05 14:25:00', 1, 2, 39, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2922, 0, '2022-10-05 14:25:00', 1, 2, 40, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2923, 0, '2022-10-05 14:25:00', 1, 2, 41, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2924, 0, '2022-10-05 14:25:00', 1, 2, 42, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2925, 0, '2022-10-05 14:25:00', 1, 3, 0, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2926, 0, '2022-10-05 14:25:00', 1, 3, 1, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2927, 0, '2022-10-05 14:25:00', 1, 3, 2, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2928, 0, '2022-10-05 14:25:00', 1, 3, 3, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2929, 0, '2022-10-05 14:25:00', 1, 3, 4, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2930, 0, '2022-10-05 14:25:00', 1, 3, 5, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2931, 0, '2022-10-05 14:25:00', 1, 3, 6, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2932, 0, '2022-10-05 14:25:00', 1, 3, 7, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2933, 0, '2022-10-05 14:25:00', 1, 3, 8, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2934, 0, '2022-10-05 14:25:00', 1, 3, 9, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2935, 0, '2022-10-05 14:25:00', 1, 3, 10, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2936, 0, '2022-10-05 14:25:00', 1, 3, 11, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2937, 0, '2022-10-05 14:25:00', 1, 3, 12, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2938, 0, '2022-10-05 14:25:00', 1, 3, 13, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2939, 0, '2022-10-05 14:25:00', 1, 3, 14, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2940, 0, '2022-10-05 14:25:00', 1, 3, 15, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2941, 0, '2022-10-05 14:25:00', 1, 3, 16, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2942, 0, '2022-10-05 14:25:00', 1, 3, 17, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2943, 0, '2022-10-05 14:25:00', 1, 3, 18, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2944, 0, '2022-10-05 14:25:00', 1, 3, 19, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2945, 0, '2022-10-05 14:25:00', 1, 3, 20, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2946, 0, '2022-10-05 14:25:00', 1, 3, 21, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2947, 0, '2022-10-05 14:25:00', 1, 3, 22, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2948, 0, '2022-10-05 14:25:00', 1, 3, 23, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2949, 0, '2022-10-05 14:25:00', 1, 3, 24, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2950, 0, '2022-10-05 14:25:00', 1, 3, 25, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2951, 0, '2022-10-05 14:25:00', 1, 3, 26, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2952, 0, '2022-10-05 14:25:00', 1, 3, 27, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2953, 0, '2022-10-05 14:25:00', 1, 3, 28, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2954, 0, '2022-10-05 14:25:00', 1, 3, 29, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2955, 0, '2022-10-05 14:25:00', 1, 3, 30, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2956, 0, '2022-10-05 14:25:00', 1, 3, 31, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2957, 0, '2022-10-05 14:25:00', 1, 3, 32, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2958, 0, '2022-10-05 14:25:00', 1, 3, 33, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2959, 0, '2022-10-05 14:25:00', 1, 3, 34, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2960, 0, '2022-10-05 14:25:00', 1, 3, 35, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2961, 0, '2022-10-05 14:25:00', 1, 3, 36, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2962, 0, '2022-10-05 14:25:00', 1, 3, 37, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2963, 0, '2022-10-05 14:25:00', 1, 3, 38, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2964, 0, '2022-10-05 14:25:00', 1, 3, 39, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2965, 0, '2022-10-05 14:25:00', 1, 3, 40, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2966, 0, '2022-10-05 14:25:00', 1, 3, 41, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2967, 0, '2022-10-05 14:25:00', 1, 3, 42, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2968, 0, '2022-10-05 14:30:00', 1, 1, 0, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2969, 0, '2022-10-05 14:30:00', 1, 1, 1, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2970, 0, '2022-10-05 14:30:00', 1, 1, 2, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2971, 0, '2022-10-05 14:30:00', 1, 1, 3, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2972, 0, '2022-10-05 14:30:00', 1, 1, 4, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2973, 0, '2022-10-05 14:30:00', 1, 1, 5, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2974, 0, '2022-10-05 14:30:00', 1, 1, 6, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2975, 0, '2022-10-05 14:30:00', 1, 1, 7, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2976, 0, '2022-10-05 14:30:00', 1, 1, 8, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2977, 0, '2022-10-05 14:30:00', 1, 1, 9, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2978, 0, '2022-10-05 14:30:00', 1, 1, 10, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2979, 0, '2022-10-05 14:30:00', 1, 1, 11, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2980, 0, '2022-10-05 14:30:00', 1, 1, 12, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2981, 0, '2022-10-05 14:30:00', 1, 1, 13, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2982, 0, '2022-10-05 14:30:00', 1, 1, 14, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2983, 0, '2022-10-05 14:30:00', 1, 1, 15, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2984, 0, '2022-10-05 14:30:00', 1, 1, 16, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2985, 0, '2022-10-05 14:30:00', 1, 1, 17, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2986, 0, '2022-10-05 14:30:00', 1, 1, 18, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2987, 0, '2022-10-05 14:30:00', 1, 1, 19, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2988, 0, '2022-10-05 14:30:00', 1, 1, 20, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2989, 0, '2022-10-05 14:30:00', 1, 1, 21, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2990, 0, '2022-10-05 14:30:00', 1, 1, 22, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2991, 0, '2022-10-05 14:30:00', 1, 1, 23, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2992, 0, '2022-10-05 14:30:00', 1, 1, 24, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2993, 0, '2022-10-05 14:30:00', 1, 1, 25, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2994, 0, '2022-10-05 14:30:00', 1, 1, 26, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2995, 0, '2022-10-05 14:30:00', 1, 1, 27, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2996, 0, '2022-10-05 14:30:00', 1, 1, 28, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2997, 0, '2022-10-05 14:30:00', 1, 1, 29, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2998, 0, '2022-10-05 14:30:00', 1, 1, 30, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (2999, 0, '2022-10-05 14:30:00', 1, 1, 31, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (3000, 0, '2022-10-05 14:30:00', 1, 1, 32, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (3001, 0, '2022-10-05 14:30:00', 1, 1, 33, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (3002, 0, '2022-10-05 14:30:00', 1, 1, 34, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (3003, 0, '2022-10-05 14:30:00', 1, 1, 35, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (3004, 0, '2022-10-05 14:30:00', 1, 1, 36, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (3005, 0, '2022-10-05 14:30:00', 1, 1, 37, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (3006, 0, '2022-10-05 14:30:00', 1, 1, 38, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (3007, 0, '2022-10-05 14:30:00', 1, 1, 39, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (3008, 0, '2022-10-05 14:30:00', 1, 1, 40, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (3009, 0, '2022-10-05 14:30:00', 1, 1, 41, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (3010, 0, '2022-10-05 14:30:00', 1, 1, 42, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (3011, 0, '2022-10-05 14:30:00', 1, 2, 0, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (3012, 0, '2022-10-05 14:30:00', 1, 2, 1, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (3013, 0, '2022-10-05 14:30:00', 1, 2, 2, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (3014, 0, '2022-10-05 14:30:00', 1, 2, 3, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (3015, 0, '2022-10-05 14:30:00', 1, 2, 4, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (3016, 0, '2022-10-05 14:30:00', 1, 2, 5, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (3017, 0, '2022-10-05 14:30:00', 1, 2, 6, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (3018, 0, '2022-10-05 14:30:00', 1, 2, 7, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (3019, 0, '2022-10-05 14:30:00', 1, 2, 8, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (3020, 0, '2022-10-05 14:30:00', 1, 2, 9, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (3021, 0, '2022-10-05 14:30:00', 1, 2, 10, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (3022, 0, '2022-10-05 14:30:00', 1, 2, 11, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (3023, 0, '2022-10-05 14:30:00', 1, 2, 12, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (3024, 0, '2022-10-05 14:30:00', 1, 2, 13, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (3025, 0, '2022-10-05 14:30:00', 1, 2, 14, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (3026, 0, '2022-10-05 14:30:00', 1, 2, 15, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (3027, 0, '2022-10-05 14:30:00', 1, 2, 16, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (3028, 0, '2022-10-05 14:30:00', 1, 2, 17, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (3029, 0, '2022-10-05 14:30:00', 1, 2, 18, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (3030, 0, '2022-10-05 14:30:00', 1, 2, 19, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (3031, 0, '2022-10-05 14:30:00', 1, 2, 20, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (3032, 0, '2022-10-05 14:30:00', 1, 2, 21, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (3033, 0, '2022-10-05 14:30:00', 1, 2, 22, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (3034, 0, '2022-10-05 14:30:00', 1, 2, 23, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (3035, 0, '2022-10-05 14:30:00', 1, 2, 24, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (3036, 0, '2022-10-05 14:30:00', 1, 2, 25, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (3037, 0, '2022-10-05 14:30:00', 1, 2, 26, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (3038, 0, '2022-10-05 14:30:00', 1, 2, 27, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (3039, 0, '2022-10-05 14:30:00', 1, 2, 28, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (3040, 0, '2022-10-05 14:30:00', 1, 2, 29, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (3041, 0, '2022-10-05 14:30:00', 1, 2, 30, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (3042, 0, '2022-10-05 14:30:00', 1, 2, 31, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (3043, 0, '2022-10-05 14:30:00', 1, 2, 32, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (3044, 0, '2022-10-05 14:30:00', 1, 2, 33, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (3045, 0, '2022-10-05 14:30:00', 1, 2, 34, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (3046, 0, '2022-10-05 14:30:00', 1, 2, 35, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (3047, 0, '2022-10-05 14:30:00', 1, 2, 36, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (3048, 0, '2022-10-05 14:30:00', 1, 2, 37, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (3049, 0, '2022-10-05 14:30:00', 1, 2, 38, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (3050, 0, '2022-10-05 14:30:00', 1, 2, 39, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (3051, 0, '2022-10-05 14:30:00', 1, 2, 40, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (3052, 0, '2022-10-05 14:30:00', 1, 2, 41, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (3053, 0, '2022-10-05 14:30:00', 1, 2, 42, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (3054, 0, '2022-10-05 14:30:00', 1, 3, 0, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (3055, 0, '2022-10-05 14:30:00', 1, 3, 1, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (3056, 0, '2022-10-05 14:30:00', 1, 3, 2, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (3057, 0, '2022-10-05 14:30:00', 1, 3, 3, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (3058, 0, '2022-10-05 14:30:00', 1, 3, 4, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (3059, 0, '2022-10-05 14:30:00', 1, 3, 5, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (3060, 0, '2022-10-05 14:30:00', 1, 3, 6, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (3061, 0, '2022-10-05 14:30:00', 1, 3, 7, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (3062, 0, '2022-10-05 14:30:00', 1, 3, 8, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (3063, 0, '2022-10-05 14:30:00', 1, 3, 9, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (3064, 0, '2022-10-05 14:30:00', 1, 3, 10, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (3065, 0, '2022-10-05 14:30:00', 1, 3, 11, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (3066, 0, '2022-10-05 14:30:00', 1, 3, 12, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (3067, 0, '2022-10-05 14:30:00', 1, 3, 13, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (3068, 0, '2022-10-05 14:30:00', 1, 3, 14, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (3069, 0, '2022-10-05 14:30:00', 1, 3, 15, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (3070, 0, '2022-10-05 14:30:00', 1, 3, 16, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (3071, 0, '2022-10-05 14:30:00', 1, 3, 17, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (3072, 0, '2022-10-05 14:30:00', 1, 3, 18, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (3073, 0, '2022-10-05 14:30:00', 1, 3, 19, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (3074, 0, '2022-10-05 14:30:00', 1, 3, 20, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (3075, 0, '2022-10-05 14:30:00', 1, 3, 21, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (3076, 0, '2022-10-05 14:30:00', 1, 3, 22, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (3077, 0, '2022-10-05 14:30:00', 1, 3, 23, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (3078, 0, '2022-10-05 14:30:00', 1, 3, 24, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (3079, 0, '2022-10-05 14:30:00', 1, 3, 25, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (3080, 0, '2022-10-05 14:30:00', 1, 3, 26, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (3081, 0, '2022-10-05 14:30:00', 1, 3, 27, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (3082, 0, '2022-10-05 14:30:00', 1, 3, 28, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (3083, 0, '2022-10-05 14:30:00', 1, 3, 29, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (3084, 0, '2022-10-05 14:30:00', 1, 3, 30, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (3085, 0, '2022-10-05 14:30:00', 1, 3, 31, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (3086, 0, '2022-10-05 14:30:00', 1, 3, 32, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (3087, 0, '2022-10-05 14:30:00', 1, 3, 33, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (3088, 0, '2022-10-05 14:30:00', 1, 3, 34, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (3089, 0, '2022-10-05 14:30:00', 1, 3, 35, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (3090, 0, '2022-10-05 14:30:00', 1, 3, 36, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (3091, 0, '2022-10-05 14:30:00', 1, 3, 37, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (3092, 0, '2022-10-05 14:30:00', 1, 3, 38, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (3093, 0, '2022-10-05 14:30:00', 1, 3, 39, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (3094, 0, '2022-10-05 14:30:00', 1, 3, 40, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (3095, 0, '2022-10-05 14:30:00', 1, 3, 41, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (3096, 0, '2022-10-05 14:30:00', 1, 3, 42, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (3097, 2, '2022-10-05 14:35:00', 1, 1, 0, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (3098, 0, '2022-10-05 14:35:00', 1, 1, 1, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (3099, 0, '2022-10-05 14:35:00', 1, 1, 2, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (3100, 0, '2022-10-05 14:35:00', 1, 1, 3, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (3101, 0, '2022-10-05 14:35:00', 1, 1, 4, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (3102, 0, '2022-10-05 14:35:00', 1, 1, 5, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (3103, 0, '2022-10-05 14:35:00', 1, 1, 6, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (3104, 0, '2022-10-05 14:35:00', 1, 1, 7, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (3105, 0, '2022-10-05 14:35:00', 1, 1, 8, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (3106, 0, '2022-10-05 14:35:00', 1, 1, 9, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (3107, 0, '2022-10-05 14:35:00', 1, 1, 10, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (3108, 0, '2022-10-05 14:35:00', 1, 1, 11, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (3109, 0, '2022-10-05 14:35:00', 1, 1, 12, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (3110, 0, '2022-10-05 14:35:00', 1, 1, 13, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (3111, 0, '2022-10-05 14:35:00', 1, 1, 14, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (3112, 0, '2022-10-05 14:35:00', 1, 1, 15, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (3113, 0, '2022-10-05 14:35:00', 1, 1, 16, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (3114, 0, '2022-10-05 14:35:00', 1, 1, 17, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (3115, 0, '2022-10-05 14:35:00', 1, 1, 18, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (3116, 0, '2022-10-05 14:35:00', 1, 1, 19, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (3117, 0, '2022-10-05 14:35:00', 1, 1, 20, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (3118, 0, '2022-10-05 14:35:00', 1, 1, 21, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (3119, 0, '2022-10-05 14:35:00', 1, 1, 22, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (3120, 0, '2022-10-05 14:35:00', 1, 1, 23, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (3121, 0, '2022-10-05 14:35:00', 1, 1, 24, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (3122, 0, '2022-10-05 14:35:00', 1, 1, 25, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (3123, 0, '2022-10-05 14:35:00', 1, 1, 26, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (3124, 0, '2022-10-05 14:35:00', 1, 1, 27, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (3125, 0, '2022-10-05 14:35:00', 1, 1, 28, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (3126, 0, '2022-10-05 14:35:00', 1, 1, 29, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (3127, 0, '2022-10-05 14:35:00', 1, 1, 30, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (3128, 0, '2022-10-05 14:35:00', 1, 1, 31, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (3129, 0, '2022-10-05 14:35:00', 1, 1, 32, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (3130, 0, '2022-10-05 14:35:00', 1, 1, 33, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (3131, 0, '2022-10-05 14:35:00', 1, 1, 34, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (3132, 0, '2022-10-05 14:35:00', 1, 1, 35, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (3133, 0, '2022-10-05 14:35:00', 1, 1, 36, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (3134, 0, '2022-10-05 14:35:00', 1, 1, 37, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (3135, 0, '2022-10-05 14:35:00', 1, 1, 38, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (3136, 0, '2022-10-05 14:35:00', 1, 1, 39, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (3137, 0, '2022-10-05 14:35:00', 1, 1, 40, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (3138, 0, '2022-10-05 14:35:00', 1, 1, 41, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (3139, 0, '2022-10-05 14:35:00', 1, 1, 42, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (3140, 0, '2022-10-05 14:35:00', 1, 2, 0, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (3141, 0, '2022-10-05 14:35:00', 1, 2, 1, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (3142, 0, '2022-10-05 14:35:00', 1, 2, 2, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (3143, 0, '2022-10-05 14:35:00', 1, 2, 3, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (3144, 0, '2022-10-05 14:35:00', 1, 2, 4, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (3145, 0, '2022-10-05 14:35:00', 1, 2, 5, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (3146, 0, '2022-10-05 14:35:00', 1, 2, 6, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (3147, 0, '2022-10-05 14:35:00', 1, 2, 7, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (3148, 0, '2022-10-05 14:35:00', 1, 2, 8, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (3149, 0, '2022-10-05 14:35:00', 1, 2, 9, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (3150, 0, '2022-10-05 14:35:00', 1, 2, 10, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (3151, 0, '2022-10-05 14:35:00', 1, 2, 11, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (3152, 0, '2022-10-05 14:35:00', 1, 2, 12, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (3153, 0, '2022-10-05 14:35:00', 1, 2, 13, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (3154, 0, '2022-10-05 14:35:00', 1, 2, 14, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (3155, 0, '2022-10-05 14:35:00', 1, 2, 15, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (3156, 0, '2022-10-05 14:35:00', 1, 2, 16, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (3157, 0, '2022-10-05 14:35:00', 1, 2, 17, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (3158, 0, '2022-10-05 14:35:00', 1, 2, 18, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (3159, 0, '2022-10-05 14:35:00', 1, 2, 19, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (3160, 0, '2022-10-05 14:35:00', 1, 2, 20, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (3161, 0, '2022-10-05 14:35:00', 1, 2, 21, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (3162, 0, '2022-10-05 14:35:00', 1, 2, 22, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (3163, 0, '2022-10-05 14:35:00', 1, 2, 23, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (3164, 0, '2022-10-05 14:35:00', 1, 2, 24, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (3165, 0, '2022-10-05 14:35:00', 1, 2, 25, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (3166, 0, '2022-10-05 14:35:00', 1, 2, 26, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (3167, 0, '2022-10-05 14:35:00', 1, 2, 27, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (3168, 0, '2022-10-05 14:35:00', 1, 2, 28, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (3169, 0, '2022-10-05 14:35:00', 1, 2, 29, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (3170, 0, '2022-10-05 14:35:00', 1, 2, 30, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (3171, 0, '2022-10-05 14:35:00', 1, 2, 31, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (3172, 0, '2022-10-05 14:35:00', 1, 2, 32, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (3173, 0, '2022-10-05 14:35:00', 1, 2, 33, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (3174, 0, '2022-10-05 14:35:00', 1, 2, 34, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (3175, 0, '2022-10-05 14:35:00', 1, 2, 35, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (3176, 0, '2022-10-05 14:35:00', 1, 2, 36, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (3177, 0, '2022-10-05 14:35:00', 1, 2, 37, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (3178, 0, '2022-10-05 14:35:00', 1, 2, 38, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (3179, 0, '2022-10-05 14:35:00', 1, 2, 39, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (3180, 0, '2022-10-05 14:35:00', 1, 2, 40, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (3181, 0, '2022-10-05 14:35:00', 1, 2, 41, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (3182, 0, '2022-10-05 14:35:00', 1, 2, 42, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (3183, 0, '2022-10-05 14:35:00', 1, 3, 0, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (3184, 0, '2022-10-05 14:35:00', 1, 3, 1, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (3185, 0, '2022-10-05 14:35:00', 1, 3, 2, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (3186, 0, '2022-10-05 14:35:00', 1, 3, 3, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (3187, 0, '2022-10-05 14:35:00', 1, 3, 4, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (3188, 0, '2022-10-05 14:35:00', 1, 3, 5, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (3189, 0, '2022-10-05 14:35:00', 1, 3, 6, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (3190, 0, '2022-10-05 14:35:00', 1, 3, 7, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (3191, 0, '2022-10-05 14:35:00', 1, 3, 8, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (3192, 0, '2022-10-05 14:35:00', 1, 3, 9, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (3193, 0, '2022-10-05 14:35:00', 1, 3, 10, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (3194, 0, '2022-10-05 14:35:00', 1, 3, 11, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (3195, 0, '2022-10-05 14:35:00', 1, 3, 12, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (3196, 0, '2022-10-05 14:35:00', 1, 3, 13, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (3197, 0, '2022-10-05 14:35:00', 1, 3, 14, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (3198, 0, '2022-10-05 14:35:00', 1, 3, 15, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (3199, 0, '2022-10-05 14:35:00', 1, 3, 16, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (3200, 0, '2022-10-05 14:35:00', 1, 3, 17, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (3201, 0, '2022-10-05 14:35:00', 1, 3, 18, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (3202, 0, '2022-10-05 14:35:00', 1, 3, 19, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (3203, 0, '2022-10-05 14:35:00', 1, 3, 20, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (3204, 0, '2022-10-05 14:35:00', 1, 3, 21, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (3205, 0, '2022-10-05 14:35:00', 1, 3, 22, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (3206, 0, '2022-10-05 14:35:00', 1, 3, 23, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (3207, 0, '2022-10-05 14:35:00', 1, 3, 24, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (3208, 0, '2022-10-05 14:35:00', 1, 3, 25, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (3209, 0, '2022-10-05 14:35:00', 1, 3, 26, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (3210, 0, '2022-10-05 14:35:00', 1, 3, 27, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (3211, 0, '2022-10-05 14:35:00', 1, 3, 28, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (3212, 0, '2022-10-05 14:35:00', 1, 3, 29, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (3213, 0, '2022-10-05 14:35:00', 1, 3, 30, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (3214, 0, '2022-10-05 14:35:00', 1, 3, 31, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (3215, 0, '2022-10-05 14:35:00', 1, 3, 32, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (3216, 0, '2022-10-05 14:35:00', 1, 3, 33, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (3217, 0, '2022-10-05 14:35:00', 1, 3, 34, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (3218, 0, '2022-10-05 14:35:00', 1, 3, 35, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (3219, 0, '2022-10-05 14:35:00', 1, 3, 36, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (3220, 0, '2022-10-05 14:35:00', 1, 3, 37, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (3221, 0, '2022-10-05 14:35:00', 1, 3, 38, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (3222, 0, '2022-10-05 14:35:00', 1, 3, 39, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (3223, 0, '2022-10-05 14:35:00', 1, 3, 40, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (3224, 0, '2022-10-05 14:35:00', 1, 3, 41, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (3225, 0, '2022-10-05 14:35:00', 1, 3, 42, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (3226, 2, '2022-10-05 14:40:00', 1, 1, 0, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (3227, 0, '2022-10-05 14:40:00', 1, 1, 1, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (3228, 0, '2022-10-05 14:40:00', 1, 1, 2, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (3229, 0, '2022-10-05 14:40:00', 1, 1, 3, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (3230, 0, '2022-10-05 14:40:00', 1, 1, 4, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (3231, 0, '2022-10-05 14:40:00', 1, 1, 5, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (3232, 0, '2022-10-05 14:40:00', 1, 1, 6, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (3233, 0, '2022-10-05 14:40:00', 1, 1, 7, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (3234, 0, '2022-10-05 14:40:00', 1, 1, 8, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (3235, 0, '2022-10-05 14:40:00', 1, 1, 9, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (3236, 0, '2022-10-05 14:40:00', 1, 1, 10, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (3237, 0, '2022-10-05 14:40:00', 1, 1, 11, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (3238, 0, '2022-10-05 14:40:00', 1, 1, 12, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (3239, 0, '2022-10-05 14:40:00', 1, 1, 13, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (3240, 0, '2022-10-05 14:40:00', 1, 1, 14, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (3241, 0, '2022-10-05 14:40:00', 1, 1, 15, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (3242, 0, '2022-10-05 14:40:00', 1, 1, 16, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (3243, 0, '2022-10-05 14:40:00', 1, 1, 17, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (3244, 0, '2022-10-05 14:40:00', 1, 1, 18, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (3245, 0, '2022-10-05 14:40:00', 1, 1, 19, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (3246, 0, '2022-10-05 14:40:00', 1, 1, 20, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (3247, 0, '2022-10-05 14:40:00', 1, 1, 21, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (3248, 0, '2022-10-05 14:40:00', 1, 1, 22, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (3249, 0, '2022-10-05 14:40:00', 1, 1, 23, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (3250, 0, '2022-10-05 14:40:00', 1, 1, 24, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (3251, 0, '2022-10-05 14:40:00', 1, 1, 25, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (3252, 0, '2022-10-05 14:40:00', 1, 1, 26, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (3253, 0, '2022-10-05 14:40:00', 1, 1, 27, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (3254, 0, '2022-10-05 14:40:00', 1, 1, 28, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (3255, 0, '2022-10-05 14:40:00', 1, 1, 29, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (3256, 0, '2022-10-05 14:40:00', 1, 1, 30, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (3257, 0, '2022-10-05 14:40:00', 1, 1, 31, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (3258, 0, '2022-10-05 14:40:00', 1, 1, 32, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (3259, 0, '2022-10-05 14:40:00', 1, 1, 33, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (3260, 0, '2022-10-05 14:40:00', 1, 1, 34, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (3261, 0, '2022-10-05 14:40:00', 1, 1, 35, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (3262, 0, '2022-10-05 14:40:00', 1, 1, 36, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (3263, 0, '2022-10-05 14:40:00', 1, 1, 37, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (3264, 0, '2022-10-05 14:40:00', 1, 1, 38, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (3265, 0, '2022-10-05 14:40:00', 1, 1, 39, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (3266, 0, '2022-10-05 14:40:00', 1, 1, 40, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (3267, 0, '2022-10-05 14:40:00', 1, 1, 41, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (3268, 0, '2022-10-05 14:40:00', 1, 1, 42, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (3269, 0, '2022-10-05 14:40:00', 1, 2, 0, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (3270, 0, '2022-10-05 14:40:00', 1, 2, 1, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (3271, 0, '2022-10-05 14:40:00', 1, 2, 2, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (3272, 0, '2022-10-05 14:40:00', 1, 2, 3, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (3273, 0, '2022-10-05 14:40:00', 1, 2, 4, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (3274, 0, '2022-10-05 14:40:00', 1, 2, 5, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (3275, 0, '2022-10-05 14:40:00', 1, 2, 6, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (3276, 0, '2022-10-05 14:40:00', 1, 2, 7, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (3277, 0, '2022-10-05 14:40:00', 1, 2, 8, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (3278, 0, '2022-10-05 14:40:00', 1, 2, 9, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (3279, 0, '2022-10-05 14:40:00', 1, 2, 10, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (3280, 0, '2022-10-05 14:40:00', 1, 2, 11, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (3281, 0, '2022-10-05 14:40:00', 1, 2, 12, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (3282, 0, '2022-10-05 14:40:00', 1, 2, 13, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (3283, 0, '2022-10-05 14:40:00', 1, 2, 14, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (3284, 0, '2022-10-05 14:40:00', 1, 2, 15, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (3285, 0, '2022-10-05 14:40:00', 1, 2, 16, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (3286, 0, '2022-10-05 14:40:00', 1, 2, 17, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (3287, 0, '2022-10-05 14:40:00', 1, 2, 18, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (3288, 0, '2022-10-05 14:40:00', 1, 2, 19, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (3289, 0, '2022-10-05 14:40:00', 1, 2, 20, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (3290, 0, '2022-10-05 14:40:00', 1, 2, 21, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (3291, 0, '2022-10-05 14:40:00', 1, 2, 22, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (3292, 0, '2022-10-05 14:40:00', 1, 2, 23, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (3293, 0, '2022-10-05 14:40:00', 1, 2, 24, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (3294, 0, '2022-10-05 14:40:00', 1, 2, 25, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (3295, 0, '2022-10-05 14:40:00', 1, 2, 26, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (3296, 0, '2022-10-05 14:40:00', 1, 2, 27, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (3297, 0, '2022-10-05 14:40:00', 1, 2, 28, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (3298, 0, '2022-10-05 14:40:00', 1, 2, 29, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (3299, 0, '2022-10-05 14:40:00', 1, 2, 30, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (3300, 0, '2022-10-05 14:40:00', 1, 2, 31, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (3301, 0, '2022-10-05 14:40:00', 1, 2, 32, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (3302, 0, '2022-10-05 14:40:00', 1, 2, 33, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (3303, 0, '2022-10-05 14:40:00', 1, 2, 34, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (3304, 0, '2022-10-05 14:40:00', 1, 2, 35, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (3305, 0, '2022-10-05 14:40:00', 1, 2, 36, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (3306, 0, '2022-10-05 14:40:00', 1, 2, 37, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (3307, 0, '2022-10-05 14:40:00', 1, 2, 38, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (3308, 0, '2022-10-05 14:40:00', 1, 2, 39, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (3309, 0, '2022-10-05 14:40:00', 1, 2, 40, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (3310, 0, '2022-10-05 14:40:00', 1, 2, 41, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (3311, 0, '2022-10-05 14:40:00', 1, 2, 42, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (3312, 0, '2022-10-05 14:40:00', 1, 3, 0, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (3313, 0, '2022-10-05 14:40:00', 1, 3, 1, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (3314, 0, '2022-10-05 14:40:00', 1, 3, 2, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (3315, 0, '2022-10-05 14:40:00', 1, 3, 3, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (3316, 0, '2022-10-05 14:40:00', 1, 3, 4, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (3317, 0, '2022-10-05 14:40:00', 1, 3, 5, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (3318, 0, '2022-10-05 14:40:00', 1, 3, 6, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (3319, 0, '2022-10-05 14:40:00', 1, 3, 7, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (3320, 0, '2022-10-05 14:40:00', 1, 3, 8, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (3321, 0, '2022-10-05 14:40:00', 1, 3, 9, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (3322, 0, '2022-10-05 14:40:00', 1, 3, 10, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (3323, 0, '2022-10-05 14:40:00', 1, 3, 11, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (3324, 0, '2022-10-05 14:40:00', 1, 3, 12, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (3325, 0, '2022-10-05 14:40:00', 1, 3, 13, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (3326, 0, '2022-10-05 14:40:00', 1, 3, 14, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (3327, 0, '2022-10-05 14:40:00', 1, 3, 15, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (3328, 0, '2022-10-05 14:40:00', 1, 3, 16, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (3329, 0, '2022-10-05 14:40:00', 1, 3, 17, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (3330, 0, '2022-10-05 14:40:00', 1, 3, 18, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (3331, 0, '2022-10-05 14:40:00', 1, 3, 19, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (3332, 0, '2022-10-05 14:40:00', 1, 3, 20, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (3333, 0, '2022-10-05 14:40:00', 1, 3, 21, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (3334, 0, '2022-10-05 14:40:00', 1, 3, 22, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (3335, 0, '2022-10-05 14:40:00', 1, 3, 23, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (3336, 0, '2022-10-05 14:40:00', 1, 3, 24, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (3337, 0, '2022-10-05 14:40:00', 1, 3, 25, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (3338, 0, '2022-10-05 14:40:00', 1, 3, 26, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (3339, 0, '2022-10-05 14:40:00', 1, 3, 27, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (3340, 0, '2022-10-05 14:40:00', 1, 3, 28, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (3341, 0, '2022-10-05 14:40:00', 1, 3, 29, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (3342, 0, '2022-10-05 14:40:00', 1, 3, 30, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (3343, 0, '2022-10-05 14:40:00', 1, 3, 31, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (3344, 0, '2022-10-05 14:40:00', 1, 3, 32, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (3345, 0, '2022-10-05 14:40:00', 1, 3, 33, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (3346, 0, '2022-10-05 14:40:00', 1, 3, 34, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (3347, 0, '2022-10-05 14:40:00', 1, 3, 35, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (3348, 0, '2022-10-05 14:40:00', 1, 3, 36, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (3349, 0, '2022-10-05 14:40:00', 1, 3, 37, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (3350, 0, '2022-10-05 14:40:00', 1, 3, 38, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (3351, 0, '2022-10-05 14:40:00', 1, 3, 39, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (3352, 0, '2022-10-05 14:40:00', 1, 3, 40, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (3353, 0, '2022-10-05 14:40:00', 1, 3, 41, 'BJ', NULL);
INSERT INTO `t_connect_count` VALUES (3354, 0, '2022-10-05 14:40:00', 1, 3, 42, 'BJ', NULL);

-- ----------------------------
-- Table structure for t_connect_log
-- ----------------------------
DROP TABLE IF EXISTS `t_connect_log`;
CREATE TABLE `t_connect_log`  (
  `a_index` int NOT NULL AUTO_INCREMENT,
  `a_idname` varchar(25) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL DEFAULT '',
  `a_date` datetime(0) NOT NULL,
  `a_ip` varchar(20) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT '0.0.0.0',
  PRIMARY KEY (`a_index`) USING BTREE,
  INDEX `idx_ip`(`a_ip`) USING BTREE,
  INDEX `idx_date`(`a_date`) USING BTREE
) ENGINE = MyISAM AUTO_INCREMENT = 4 CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Records of t_connect_log
-- ----------------------------
INSERT INTO `t_connect_log` VALUES (1, 'Aiz491', '2022-10-05 14:28:27', '127.0.0.1');
INSERT INTO `t_connect_log` VALUES (2, 'Aiz491', '2022-10-05 14:30:43', '127.0.0.1');
INSERT INTO `t_connect_log` VALUES (3, 'Nate', '2022-10-05 14:31:50', '127.0.0.1');

-- ----------------------------
-- Table structure for t_connect_max
-- ----------------------------
DROP TABLE IF EXISTS `t_connect_max`;
CREATE TABLE `t_connect_max`  (
  `a_index` int UNSIGNED NOT NULL AUTO_INCREMENT,
  `a_count` int UNSIGNED NULL DEFAULT 0,
  `a_count_max` int UNSIGNED NULL DEFAULT 0,
  `a_date` date NULL DEFAULT NULL,
  `a_server` int NULL DEFAULT 0,
  `a_sub_num` int UNSIGNED NULL DEFAULT 0,
  `a_zone_num` int UNSIGNED NOT NULL DEFAULT 0,
  `a_level_count` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
  PRIMARY KEY (`a_index`) USING BTREE,
  INDEX `idx_date_sub_zone`(`a_date`, `a_sub_num`, `a_zone_num`, `a_server`) USING BTREE,
  INDEX `idx_date`(`a_date`) USING BTREE,
  INDEX `idx_server`(`a_server`, `a_sub_num`) USING BTREE
) ENGINE = MyISAM AUTO_INCREMENT = 259 CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Records of t_connect_max
-- ----------------------------
INSERT INTO `t_connect_max` VALUES (1, 0, 0, '2022-10-04', 1, 1, 0, NULL);
INSERT INTO `t_connect_max` VALUES (2, 0, 0, '2022-10-04', 1, 1, 1, NULL);
INSERT INTO `t_connect_max` VALUES (3, 0, 0, '2022-10-04', 1, 1, 2, NULL);
INSERT INTO `t_connect_max` VALUES (4, 0, 0, '2022-10-04', 1, 1, 3, NULL);
INSERT INTO `t_connect_max` VALUES (5, 0, 0, '2022-10-04', 1, 1, 4, NULL);
INSERT INTO `t_connect_max` VALUES (6, 0, 0, '2022-10-04', 1, 1, 5, NULL);
INSERT INTO `t_connect_max` VALUES (7, 0, 0, '2022-10-04', 1, 1, 6, NULL);
INSERT INTO `t_connect_max` VALUES (8, 0, 0, '2022-10-04', 1, 1, 7, NULL);
INSERT INTO `t_connect_max` VALUES (9, 0, 0, '2022-10-04', 1, 1, 8, NULL);
INSERT INTO `t_connect_max` VALUES (10, 0, 0, '2022-10-04', 1, 1, 9, NULL);
INSERT INTO `t_connect_max` VALUES (11, 0, 0, '2022-10-04', 1, 1, 10, NULL);
INSERT INTO `t_connect_max` VALUES (12, 0, 0, '2022-10-04', 1, 1, 11, NULL);
INSERT INTO `t_connect_max` VALUES (13, 0, 0, '2022-10-04', 1, 1, 12, NULL);
INSERT INTO `t_connect_max` VALUES (14, 0, 0, '2022-10-04', 1, 1, 13, NULL);
INSERT INTO `t_connect_max` VALUES (15, 0, 0, '2022-10-04', 1, 1, 14, NULL);
INSERT INTO `t_connect_max` VALUES (16, 0, 0, '2022-10-04', 1, 1, 15, NULL);
INSERT INTO `t_connect_max` VALUES (17, 0, 0, '2022-10-04', 1, 1, 16, NULL);
INSERT INTO `t_connect_max` VALUES (18, 0, 0, '2022-10-04', 1, 1, 17, NULL);
INSERT INTO `t_connect_max` VALUES (19, 0, 0, '2022-10-04', 1, 1, 18, NULL);
INSERT INTO `t_connect_max` VALUES (20, 0, 0, '2022-10-04', 1, 1, 19, NULL);
INSERT INTO `t_connect_max` VALUES (21, 0, 0, '2022-10-04', 1, 1, 20, NULL);
INSERT INTO `t_connect_max` VALUES (22, 0, 0, '2022-10-04', 1, 1, 21, NULL);
INSERT INTO `t_connect_max` VALUES (23, 0, 0, '2022-10-04', 1, 1, 22, NULL);
INSERT INTO `t_connect_max` VALUES (24, 0, 0, '2022-10-04', 1, 1, 23, NULL);
INSERT INTO `t_connect_max` VALUES (25, 0, 0, '2022-10-04', 1, 1, 24, NULL);
INSERT INTO `t_connect_max` VALUES (26, 0, 0, '2022-10-04', 1, 1, 25, NULL);
INSERT INTO `t_connect_max` VALUES (27, 0, 0, '2022-10-04', 1, 1, 26, NULL);
INSERT INTO `t_connect_max` VALUES (28, 0, 0, '2022-10-04', 1, 1, 27, NULL);
INSERT INTO `t_connect_max` VALUES (29, 0, 0, '2022-10-04', 1, 1, 28, NULL);
INSERT INTO `t_connect_max` VALUES (30, 0, 0, '2022-10-04', 1, 1, 29, NULL);
INSERT INTO `t_connect_max` VALUES (31, 0, 0, '2022-10-04', 1, 1, 30, NULL);
INSERT INTO `t_connect_max` VALUES (32, 0, 0, '2022-10-04', 1, 1, 31, NULL);
INSERT INTO `t_connect_max` VALUES (33, 0, 0, '2022-10-04', 1, 1, 32, NULL);
INSERT INTO `t_connect_max` VALUES (34, 0, 0, '2022-10-04', 1, 1, 33, NULL);
INSERT INTO `t_connect_max` VALUES (35, 0, 0, '2022-10-04', 1, 1, 34, NULL);
INSERT INTO `t_connect_max` VALUES (36, 0, 0, '2022-10-04', 1, 1, 35, NULL);
INSERT INTO `t_connect_max` VALUES (37, 0, 0, '2022-10-04', 1, 1, 36, NULL);
INSERT INTO `t_connect_max` VALUES (38, 0, 0, '2022-10-04', 1, 1, 37, NULL);
INSERT INTO `t_connect_max` VALUES (39, 0, 0, '2022-10-04', 1, 1, 38, NULL);
INSERT INTO `t_connect_max` VALUES (40, 0, 0, '2022-10-04', 1, 1, 39, NULL);
INSERT INTO `t_connect_max` VALUES (41, 0, 0, '2022-10-04', 1, 1, 40, NULL);
INSERT INTO `t_connect_max` VALUES (42, 0, 0, '2022-10-04', 1, 1, 41, NULL);
INSERT INTO `t_connect_max` VALUES (43, 0, 0, '2022-10-04', 1, 1, 42, NULL);
INSERT INTO `t_connect_max` VALUES (44, 0, 0, '2022-10-04', 1, 2, 0, NULL);
INSERT INTO `t_connect_max` VALUES (45, 0, 0, '2022-10-04', 1, 2, 1, NULL);
INSERT INTO `t_connect_max` VALUES (46, 0, 0, '2022-10-04', 1, 2, 2, NULL);
INSERT INTO `t_connect_max` VALUES (47, 0, 0, '2022-10-04', 1, 2, 3, NULL);
INSERT INTO `t_connect_max` VALUES (48, 0, 0, '2022-10-04', 1, 2, 4, NULL);
INSERT INTO `t_connect_max` VALUES (49, 0, 0, '2022-10-04', 1, 2, 5, NULL);
INSERT INTO `t_connect_max` VALUES (50, 0, 0, '2022-10-04', 1, 2, 6, NULL);
INSERT INTO `t_connect_max` VALUES (51, 0, 0, '2022-10-04', 1, 2, 7, NULL);
INSERT INTO `t_connect_max` VALUES (52, 0, 0, '2022-10-04', 1, 2, 8, NULL);
INSERT INTO `t_connect_max` VALUES (53, 0, 0, '2022-10-04', 1, 2, 9, NULL);
INSERT INTO `t_connect_max` VALUES (54, 0, 0, '2022-10-04', 1, 2, 10, NULL);
INSERT INTO `t_connect_max` VALUES (55, 0, 0, '2022-10-04', 1, 2, 11, NULL);
INSERT INTO `t_connect_max` VALUES (56, 0, 0, '2022-10-04', 1, 2, 12, NULL);
INSERT INTO `t_connect_max` VALUES (57, 0, 0, '2022-10-04', 1, 2, 13, NULL);
INSERT INTO `t_connect_max` VALUES (58, 0, 0, '2022-10-04', 1, 2, 14, NULL);
INSERT INTO `t_connect_max` VALUES (59, 0, 0, '2022-10-04', 1, 2, 15, NULL);
INSERT INTO `t_connect_max` VALUES (60, 0, 0, '2022-10-04', 1, 2, 16, NULL);
INSERT INTO `t_connect_max` VALUES (61, 0, 0, '2022-10-04', 1, 2, 17, NULL);
INSERT INTO `t_connect_max` VALUES (62, 0, 0, '2022-10-04', 1, 2, 18, NULL);
INSERT INTO `t_connect_max` VALUES (63, 0, 0, '2022-10-04', 1, 2, 19, NULL);
INSERT INTO `t_connect_max` VALUES (64, 0, 0, '2022-10-04', 1, 2, 20, NULL);
INSERT INTO `t_connect_max` VALUES (65, 0, 0, '2022-10-04', 1, 2, 21, NULL);
INSERT INTO `t_connect_max` VALUES (66, 0, 0, '2022-10-04', 1, 2, 22, NULL);
INSERT INTO `t_connect_max` VALUES (67, 0, 0, '2022-10-04', 1, 2, 23, NULL);
INSERT INTO `t_connect_max` VALUES (68, 0, 0, '2022-10-04', 1, 2, 24, NULL);
INSERT INTO `t_connect_max` VALUES (69, 0, 0, '2022-10-04', 1, 2, 25, NULL);
INSERT INTO `t_connect_max` VALUES (70, 0, 0, '2022-10-04', 1, 2, 26, NULL);
INSERT INTO `t_connect_max` VALUES (71, 0, 0, '2022-10-04', 1, 2, 27, NULL);
INSERT INTO `t_connect_max` VALUES (72, 0, 0, '2022-10-04', 1, 2, 28, NULL);
INSERT INTO `t_connect_max` VALUES (73, 0, 0, '2022-10-04', 1, 2, 29, NULL);
INSERT INTO `t_connect_max` VALUES (74, 0, 0, '2022-10-04', 1, 2, 30, NULL);
INSERT INTO `t_connect_max` VALUES (75, 0, 0, '2022-10-04', 1, 2, 31, NULL);
INSERT INTO `t_connect_max` VALUES (76, 0, 0, '2022-10-04', 1, 2, 32, NULL);
INSERT INTO `t_connect_max` VALUES (77, 0, 0, '2022-10-04', 1, 2, 33, NULL);
INSERT INTO `t_connect_max` VALUES (78, 0, 0, '2022-10-04', 1, 2, 34, NULL);
INSERT INTO `t_connect_max` VALUES (79, 0, 0, '2022-10-04', 1, 2, 35, NULL);
INSERT INTO `t_connect_max` VALUES (80, 0, 0, '2022-10-04', 1, 2, 36, NULL);
INSERT INTO `t_connect_max` VALUES (81, 0, 0, '2022-10-04', 1, 2, 37, NULL);
INSERT INTO `t_connect_max` VALUES (82, 0, 0, '2022-10-04', 1, 2, 38, NULL);
INSERT INTO `t_connect_max` VALUES (83, 0, 0, '2022-10-04', 1, 2, 39, NULL);
INSERT INTO `t_connect_max` VALUES (84, 0, 0, '2022-10-04', 1, 2, 40, NULL);
INSERT INTO `t_connect_max` VALUES (85, 0, 0, '2022-10-04', 1, 2, 41, NULL);
INSERT INTO `t_connect_max` VALUES (86, 0, 0, '2022-10-04', 1, 2, 42, NULL);
INSERT INTO `t_connect_max` VALUES (87, 0, 0, '2022-10-04', 1, 3, 0, NULL);
INSERT INTO `t_connect_max` VALUES (88, 0, 0, '2022-10-04', 1, 3, 1, NULL);
INSERT INTO `t_connect_max` VALUES (89, 0, 0, '2022-10-04', 1, 3, 2, NULL);
INSERT INTO `t_connect_max` VALUES (90, 0, 0, '2022-10-04', 1, 3, 3, NULL);
INSERT INTO `t_connect_max` VALUES (91, 0, 0, '2022-10-04', 1, 3, 4, NULL);
INSERT INTO `t_connect_max` VALUES (92, 0, 0, '2022-10-04', 1, 3, 5, NULL);
INSERT INTO `t_connect_max` VALUES (93, 0, 0, '2022-10-04', 1, 3, 6, NULL);
INSERT INTO `t_connect_max` VALUES (94, 0, 0, '2022-10-04', 1, 3, 7, NULL);
INSERT INTO `t_connect_max` VALUES (95, 0, 0, '2022-10-04', 1, 3, 8, NULL);
INSERT INTO `t_connect_max` VALUES (96, 0, 0, '2022-10-04', 1, 3, 9, NULL);
INSERT INTO `t_connect_max` VALUES (97, 0, 0, '2022-10-04', 1, 3, 10, NULL);
INSERT INTO `t_connect_max` VALUES (98, 0, 0, '2022-10-04', 1, 3, 11, NULL);
INSERT INTO `t_connect_max` VALUES (99, 0, 0, '2022-10-04', 1, 3, 12, NULL);
INSERT INTO `t_connect_max` VALUES (100, 0, 0, '2022-10-04', 1, 3, 13, NULL);
INSERT INTO `t_connect_max` VALUES (101, 0, 0, '2022-10-04', 1, 3, 14, NULL);
INSERT INTO `t_connect_max` VALUES (102, 0, 0, '2022-10-04', 1, 3, 15, NULL);
INSERT INTO `t_connect_max` VALUES (103, 0, 0, '2022-10-04', 1, 3, 16, NULL);
INSERT INTO `t_connect_max` VALUES (104, 0, 0, '2022-10-04', 1, 3, 17, NULL);
INSERT INTO `t_connect_max` VALUES (105, 0, 0, '2022-10-04', 1, 3, 18, NULL);
INSERT INTO `t_connect_max` VALUES (106, 0, 0, '2022-10-04', 1, 3, 19, NULL);
INSERT INTO `t_connect_max` VALUES (107, 0, 0, '2022-10-04', 1, 3, 20, NULL);
INSERT INTO `t_connect_max` VALUES (108, 0, 0, '2022-10-04', 1, 3, 21, NULL);
INSERT INTO `t_connect_max` VALUES (109, 0, 0, '2022-10-04', 1, 3, 22, NULL);
INSERT INTO `t_connect_max` VALUES (110, 0, 0, '2022-10-04', 1, 3, 23, NULL);
INSERT INTO `t_connect_max` VALUES (111, 0, 0, '2022-10-04', 1, 3, 24, NULL);
INSERT INTO `t_connect_max` VALUES (112, 0, 0, '2022-10-04', 1, 3, 25, NULL);
INSERT INTO `t_connect_max` VALUES (113, 0, 0, '2022-10-04', 1, 3, 26, NULL);
INSERT INTO `t_connect_max` VALUES (114, 0, 0, '2022-10-04', 1, 3, 27, NULL);
INSERT INTO `t_connect_max` VALUES (115, 0, 0, '2022-10-04', 1, 3, 28, NULL);
INSERT INTO `t_connect_max` VALUES (116, 0, 0, '2022-10-04', 1, 3, 29, NULL);
INSERT INTO `t_connect_max` VALUES (117, 0, 0, '2022-10-04', 1, 3, 30, NULL);
INSERT INTO `t_connect_max` VALUES (118, 0, 0, '2022-10-04', 1, 3, 31, NULL);
INSERT INTO `t_connect_max` VALUES (119, 0, 0, '2022-10-04', 1, 3, 32, NULL);
INSERT INTO `t_connect_max` VALUES (120, 0, 0, '2022-10-04', 1, 3, 33, NULL);
INSERT INTO `t_connect_max` VALUES (121, 0, 0, '2022-10-04', 1, 3, 34, NULL);
INSERT INTO `t_connect_max` VALUES (122, 0, 0, '2022-10-04', 1, 3, 35, NULL);
INSERT INTO `t_connect_max` VALUES (123, 0, 0, '2022-10-04', 1, 3, 36, NULL);
INSERT INTO `t_connect_max` VALUES (124, 0, 0, '2022-10-04', 1, 3, 37, NULL);
INSERT INTO `t_connect_max` VALUES (125, 0, 0, '2022-10-04', 1, 3, 38, NULL);
INSERT INTO `t_connect_max` VALUES (126, 0, 0, '2022-10-04', 1, 3, 39, NULL);
INSERT INTO `t_connect_max` VALUES (127, 0, 0, '2022-10-04', 1, 3, 40, NULL);
INSERT INTO `t_connect_max` VALUES (128, 0, 0, '2022-10-04', 1, 3, 41, NULL);
INSERT INTO `t_connect_max` VALUES (129, 0, 0, '2022-10-04', 1, 3, 42, NULL);
INSERT INTO `t_connect_max` VALUES (130, 2, 2, '2022-10-05', 1, 1, 0, NULL);
INSERT INTO `t_connect_max` VALUES (131, 0, 0, '2022-10-05', 1, 1, 1, NULL);
INSERT INTO `t_connect_max` VALUES (132, 0, 0, '2022-10-05', 1, 1, 2, NULL);
INSERT INTO `t_connect_max` VALUES (133, 0, 0, '2022-10-05', 1, 1, 3, NULL);
INSERT INTO `t_connect_max` VALUES (134, 0, 0, '2022-10-05', 1, 1, 4, NULL);
INSERT INTO `t_connect_max` VALUES (135, 0, 0, '2022-10-05', 1, 1, 5, NULL);
INSERT INTO `t_connect_max` VALUES (136, 0, 0, '2022-10-05', 1, 1, 6, NULL);
INSERT INTO `t_connect_max` VALUES (137, 0, 0, '2022-10-05', 1, 1, 7, NULL);
INSERT INTO `t_connect_max` VALUES (138, 0, 0, '2022-10-05', 1, 1, 8, NULL);
INSERT INTO `t_connect_max` VALUES (139, 0, 0, '2022-10-05', 1, 1, 9, NULL);
INSERT INTO `t_connect_max` VALUES (140, 0, 0, '2022-10-05', 1, 1, 10, NULL);
INSERT INTO `t_connect_max` VALUES (141, 0, 0, '2022-10-05', 1, 1, 11, NULL);
INSERT INTO `t_connect_max` VALUES (142, 0, 0, '2022-10-05', 1, 1, 12, NULL);
INSERT INTO `t_connect_max` VALUES (143, 0, 0, '2022-10-05', 1, 1, 13, NULL);
INSERT INTO `t_connect_max` VALUES (144, 0, 0, '2022-10-05', 1, 1, 14, NULL);
INSERT INTO `t_connect_max` VALUES (145, 0, 0, '2022-10-05', 1, 1, 15, NULL);
INSERT INTO `t_connect_max` VALUES (146, 0, 0, '2022-10-05', 1, 1, 16, NULL);
INSERT INTO `t_connect_max` VALUES (147, 0, 0, '2022-10-05', 1, 1, 17, NULL);
INSERT INTO `t_connect_max` VALUES (148, 0, 0, '2022-10-05', 1, 1, 18, NULL);
INSERT INTO `t_connect_max` VALUES (149, 0, 0, '2022-10-05', 1, 1, 19, NULL);
INSERT INTO `t_connect_max` VALUES (150, 0, 0, '2022-10-05', 1, 1, 20, NULL);
INSERT INTO `t_connect_max` VALUES (151, 0, 0, '2022-10-05', 1, 1, 21, NULL);
INSERT INTO `t_connect_max` VALUES (152, 0, 0, '2022-10-05', 1, 1, 22, NULL);
INSERT INTO `t_connect_max` VALUES (153, 0, 0, '2022-10-05', 1, 1, 23, NULL);
INSERT INTO `t_connect_max` VALUES (154, 0, 0, '2022-10-05', 1, 1, 24, NULL);
INSERT INTO `t_connect_max` VALUES (155, 0, 0, '2022-10-05', 1, 1, 25, NULL);
INSERT INTO `t_connect_max` VALUES (156, 0, 0, '2022-10-05', 1, 1, 26, NULL);
INSERT INTO `t_connect_max` VALUES (157, 0, 0, '2022-10-05', 1, 1, 27, NULL);
INSERT INTO `t_connect_max` VALUES (158, 0, 0, '2022-10-05', 1, 1, 28, NULL);
INSERT INTO `t_connect_max` VALUES (159, 0, 0, '2022-10-05', 1, 1, 29, NULL);
INSERT INTO `t_connect_max` VALUES (160, 0, 0, '2022-10-05', 1, 1, 30, NULL);
INSERT INTO `t_connect_max` VALUES (161, 0, 0, '2022-10-05', 1, 1, 31, NULL);
INSERT INTO `t_connect_max` VALUES (162, 0, 0, '2022-10-05', 1, 1, 32, NULL);
INSERT INTO `t_connect_max` VALUES (163, 0, 0, '2022-10-05', 1, 1, 33, NULL);
INSERT INTO `t_connect_max` VALUES (164, 0, 0, '2022-10-05', 1, 1, 34, NULL);
INSERT INTO `t_connect_max` VALUES (165, 0, 0, '2022-10-05', 1, 1, 35, NULL);
INSERT INTO `t_connect_max` VALUES (166, 0, 0, '2022-10-05', 1, 1, 36, NULL);
INSERT INTO `t_connect_max` VALUES (167, 0, 0, '2022-10-05', 1, 1, 37, NULL);
INSERT INTO `t_connect_max` VALUES (168, 0, 0, '2022-10-05', 1, 1, 38, NULL);
INSERT INTO `t_connect_max` VALUES (169, 0, 0, '2022-10-05', 1, 1, 39, NULL);
INSERT INTO `t_connect_max` VALUES (170, 0, 0, '2022-10-05', 1, 1, 40, NULL);
INSERT INTO `t_connect_max` VALUES (171, 0, 0, '2022-10-05', 1, 1, 41, NULL);
INSERT INTO `t_connect_max` VALUES (172, 0, 0, '2022-10-05', 1, 1, 42, NULL);
INSERT INTO `t_connect_max` VALUES (173, 0, 0, '2022-10-05', 1, 2, 0, NULL);
INSERT INTO `t_connect_max` VALUES (174, 0, 0, '2022-10-05', 1, 2, 1, NULL);
INSERT INTO `t_connect_max` VALUES (175, 0, 0, '2022-10-05', 1, 2, 2, NULL);
INSERT INTO `t_connect_max` VALUES (176, 0, 0, '2022-10-05', 1, 2, 3, NULL);
INSERT INTO `t_connect_max` VALUES (177, 0, 0, '2022-10-05', 1, 2, 4, NULL);
INSERT INTO `t_connect_max` VALUES (178, 0, 0, '2022-10-05', 1, 2, 5, NULL);
INSERT INTO `t_connect_max` VALUES (179, 0, 0, '2022-10-05', 1, 2, 6, NULL);
INSERT INTO `t_connect_max` VALUES (180, 0, 0, '2022-10-05', 1, 2, 7, NULL);
INSERT INTO `t_connect_max` VALUES (181, 0, 0, '2022-10-05', 1, 2, 8, NULL);
INSERT INTO `t_connect_max` VALUES (182, 0, 0, '2022-10-05', 1, 2, 9, NULL);
INSERT INTO `t_connect_max` VALUES (183, 0, 0, '2022-10-05', 1, 2, 10, NULL);
INSERT INTO `t_connect_max` VALUES (184, 0, 0, '2022-10-05', 1, 2, 11, NULL);
INSERT INTO `t_connect_max` VALUES (185, 0, 0, '2022-10-05', 1, 2, 12, NULL);
INSERT INTO `t_connect_max` VALUES (186, 0, 0, '2022-10-05', 1, 2, 13, NULL);
INSERT INTO `t_connect_max` VALUES (187, 0, 0, '2022-10-05', 1, 2, 14, NULL);
INSERT INTO `t_connect_max` VALUES (188, 0, 0, '2022-10-05', 1, 2, 15, NULL);
INSERT INTO `t_connect_max` VALUES (189, 0, 0, '2022-10-05', 1, 2, 16, NULL);
INSERT INTO `t_connect_max` VALUES (190, 0, 0, '2022-10-05', 1, 2, 17, NULL);
INSERT INTO `t_connect_max` VALUES (191, 0, 0, '2022-10-05', 1, 2, 18, NULL);
INSERT INTO `t_connect_max` VALUES (192, 0, 0, '2022-10-05', 1, 2, 19, NULL);
INSERT INTO `t_connect_max` VALUES (193, 0, 0, '2022-10-05', 1, 2, 20, NULL);
INSERT INTO `t_connect_max` VALUES (194, 0, 0, '2022-10-05', 1, 2, 21, NULL);
INSERT INTO `t_connect_max` VALUES (195, 0, 0, '2022-10-05', 1, 2, 22, NULL);
INSERT INTO `t_connect_max` VALUES (196, 0, 0, '2022-10-05', 1, 2, 23, NULL);
INSERT INTO `t_connect_max` VALUES (197, 0, 0, '2022-10-05', 1, 2, 24, NULL);
INSERT INTO `t_connect_max` VALUES (198, 0, 0, '2022-10-05', 1, 2, 25, NULL);
INSERT INTO `t_connect_max` VALUES (199, 0, 0, '2022-10-05', 1, 2, 26, NULL);
INSERT INTO `t_connect_max` VALUES (200, 0, 0, '2022-10-05', 1, 2, 27, NULL);
INSERT INTO `t_connect_max` VALUES (201, 0, 0, '2022-10-05', 1, 2, 28, NULL);
INSERT INTO `t_connect_max` VALUES (202, 0, 0, '2022-10-05', 1, 2, 29, NULL);
INSERT INTO `t_connect_max` VALUES (203, 0, 0, '2022-10-05', 1, 2, 30, NULL);
INSERT INTO `t_connect_max` VALUES (204, 0, 0, '2022-10-05', 1, 2, 31, NULL);
INSERT INTO `t_connect_max` VALUES (205, 0, 0, '2022-10-05', 1, 2, 32, NULL);
INSERT INTO `t_connect_max` VALUES (206, 0, 0, '2022-10-05', 1, 2, 33, NULL);
INSERT INTO `t_connect_max` VALUES (207, 0, 0, '2022-10-05', 1, 2, 34, NULL);
INSERT INTO `t_connect_max` VALUES (208, 0, 0, '2022-10-05', 1, 2, 35, NULL);
INSERT INTO `t_connect_max` VALUES (209, 0, 0, '2022-10-05', 1, 2, 36, NULL);
INSERT INTO `t_connect_max` VALUES (210, 0, 0, '2022-10-05', 1, 2, 37, NULL);
INSERT INTO `t_connect_max` VALUES (211, 0, 0, '2022-10-05', 1, 2, 38, NULL);
INSERT INTO `t_connect_max` VALUES (212, 0, 0, '2022-10-05', 1, 2, 39, NULL);
INSERT INTO `t_connect_max` VALUES (213, 0, 0, '2022-10-05', 1, 2, 40, NULL);
INSERT INTO `t_connect_max` VALUES (214, 0, 0, '2022-10-05', 1, 2, 41, NULL);
INSERT INTO `t_connect_max` VALUES (215, 0, 0, '2022-10-05', 1, 2, 42, NULL);
INSERT INTO `t_connect_max` VALUES (216, 0, 0, '2022-10-05', 1, 3, 0, NULL);
INSERT INTO `t_connect_max` VALUES (217, 0, 0, '2022-10-05', 1, 3, 1, NULL);
INSERT INTO `t_connect_max` VALUES (218, 0, 0, '2022-10-05', 1, 3, 2, NULL);
INSERT INTO `t_connect_max` VALUES (219, 0, 0, '2022-10-05', 1, 3, 3, NULL);
INSERT INTO `t_connect_max` VALUES (220, 0, 0, '2022-10-05', 1, 3, 4, NULL);
INSERT INTO `t_connect_max` VALUES (221, 0, 0, '2022-10-05', 1, 3, 5, NULL);
INSERT INTO `t_connect_max` VALUES (222, 0, 0, '2022-10-05', 1, 3, 6, NULL);
INSERT INTO `t_connect_max` VALUES (223, 0, 0, '2022-10-05', 1, 3, 7, NULL);
INSERT INTO `t_connect_max` VALUES (224, 0, 0, '2022-10-05', 1, 3, 8, NULL);
INSERT INTO `t_connect_max` VALUES (225, 0, 0, '2022-10-05', 1, 3, 9, NULL);
INSERT INTO `t_connect_max` VALUES (226, 0, 0, '2022-10-05', 1, 3, 10, NULL);
INSERT INTO `t_connect_max` VALUES (227, 0, 0, '2022-10-05', 1, 3, 11, NULL);
INSERT INTO `t_connect_max` VALUES (228, 0, 0, '2022-10-05', 1, 3, 12, NULL);
INSERT INTO `t_connect_max` VALUES (229, 0, 0, '2022-10-05', 1, 3, 13, NULL);
INSERT INTO `t_connect_max` VALUES (230, 0, 0, '2022-10-05', 1, 3, 14, NULL);
INSERT INTO `t_connect_max` VALUES (231, 0, 0, '2022-10-05', 1, 3, 15, NULL);
INSERT INTO `t_connect_max` VALUES (232, 0, 0, '2022-10-05', 1, 3, 16, NULL);
INSERT INTO `t_connect_max` VALUES (233, 0, 0, '2022-10-05', 1, 3, 17, NULL);
INSERT INTO `t_connect_max` VALUES (234, 0, 0, '2022-10-05', 1, 3, 18, NULL);
INSERT INTO `t_connect_max` VALUES (235, 0, 0, '2022-10-05', 1, 3, 19, NULL);
INSERT INTO `t_connect_max` VALUES (236, 0, 0, '2022-10-05', 1, 3, 20, NULL);
INSERT INTO `t_connect_max` VALUES (237, 0, 0, '2022-10-05', 1, 3, 21, NULL);
INSERT INTO `t_connect_max` VALUES (238, 0, 0, '2022-10-05', 1, 3, 22, NULL);
INSERT INTO `t_connect_max` VALUES (239, 0, 0, '2022-10-05', 1, 3, 23, NULL);
INSERT INTO `t_connect_max` VALUES (240, 0, 0, '2022-10-05', 1, 3, 24, NULL);
INSERT INTO `t_connect_max` VALUES (241, 0, 0, '2022-10-05', 1, 3, 25, NULL);
INSERT INTO `t_connect_max` VALUES (242, 0, 0, '2022-10-05', 1, 3, 26, NULL);
INSERT INTO `t_connect_max` VALUES (243, 0, 0, '2022-10-05', 1, 3, 27, NULL);
INSERT INTO `t_connect_max` VALUES (244, 0, 0, '2022-10-05', 1, 3, 28, NULL);
INSERT INTO `t_connect_max` VALUES (245, 0, 0, '2022-10-05', 1, 3, 29, NULL);
INSERT INTO `t_connect_max` VALUES (246, 0, 0, '2022-10-05', 1, 3, 30, NULL);
INSERT INTO `t_connect_max` VALUES (247, 0, 0, '2022-10-05', 1, 3, 31, NULL);
INSERT INTO `t_connect_max` VALUES (248, 0, 0, '2022-10-05', 1, 3, 32, NULL);
INSERT INTO `t_connect_max` VALUES (249, 0, 0, '2022-10-05', 1, 3, 33, NULL);
INSERT INTO `t_connect_max` VALUES (250, 0, 0, '2022-10-05', 1, 3, 34, NULL);
INSERT INTO `t_connect_max` VALUES (251, 0, 0, '2022-10-05', 1, 3, 35, NULL);
INSERT INTO `t_connect_max` VALUES (252, 0, 0, '2022-10-05', 1, 3, 36, NULL);
INSERT INTO `t_connect_max` VALUES (253, 0, 0, '2022-10-05', 1, 3, 37, NULL);
INSERT INTO `t_connect_max` VALUES (254, 0, 0, '2022-10-05', 1, 3, 38, NULL);
INSERT INTO `t_connect_max` VALUES (255, 0, 0, '2022-10-05', 1, 3, 39, NULL);
INSERT INTO `t_connect_max` VALUES (256, 0, 0, '2022-10-05', 1, 3, 40, NULL);
INSERT INTO `t_connect_max` VALUES (257, 0, 0, '2022-10-05', 1, 3, 41, NULL);
INSERT INTO `t_connect_max` VALUES (258, 0, 0, '2022-10-05', 1, 3, 42, NULL);

-- ----------------------------
-- Table structure for t_connect_status
-- ----------------------------
DROP TABLE IF EXISTS `t_connect_status`;
CREATE TABLE `t_connect_status`  (
  `a_server` int UNSIGNED NOT NULL DEFAULT 0,
  `a_sub_num` int UNSIGNED NOT NULL DEFAULT 0,
  `a_count` int UNSIGNED NOT NULL DEFAULT 0,
  PRIMARY KEY (`a_server`, `a_sub_num`) USING BTREE
) ENGINE = MyISAM CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Fixed;

-- ----------------------------
-- Records of t_connect_status
-- ----------------------------

-- ----------------------------
-- Table structure for t_ct_limit
-- ----------------------------
DROP TABLE IF EXISTS `t_ct_limit`;
CREATE TABLE `t_ct_limit`  (
  `a_server` int NOT NULL DEFAULT -1,
  `a_ct_id` int NOT NULL DEFAULT -1,
  `a_sell` int NOT NULL DEFAULT 0,
  `a_limit` int NOT NULL DEFAULT 0,
  PRIMARY KEY (`a_ct_id`, `a_server`) USING BTREE,
  INDEX `a_ct_id_2`(`a_ct_id`) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci COMMENT = '제한상품 리스트' ROW_FORMAT = Dynamic;

-- ----------------------------
-- Records of t_ct_limit
-- ----------------------------

-- ----------------------------
-- Table structure for t_eur2_promotion
-- ----------------------------
DROP TABLE IF EXISTS `t_eur2_promotion`;
CREATE TABLE `t_eur2_promotion`  (
  `a_key` varchar(20) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL DEFAULT '',
  `a_user_index` int NOT NULL DEFAULT 0,
  `a_char_index` int NOT NULL DEFAULT 0,
  `a_use_date` datetime(0) NOT NULL,
  UNIQUE INDEX `a_key`(`a_key`) USING BTREE,
  INDEX `a_user_index`(`a_user_index`) USING BTREE
) ENGINE = MyISAM CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Records of t_eur2_promotion
-- ----------------------------

-- ----------------------------
-- Table structure for t_event
-- ----------------------------
DROP TABLE IF EXISTS `t_event`;
CREATE TABLE `t_event`  (
  `a_index` int UNSIGNED NOT NULL AUTO_INCREMENT,
  `a_good_name` varchar(30) CHARACTER SET utf8 COLLATE utf8_bin NOT NULL DEFAULT '00',
  `a_good_index` int UNSIGNED NOT NULL DEFAULT 0,
  `a_idname` varchar(30) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL DEFAULT '0',
  `a_user_index` int UNSIGNED NOT NULL DEFAULT 0,
  `a_week_index` tinyint UNSIGNED NOT NULL DEFAULT 1,
  `a_create_date` datetime(0) NOT NULL DEFAULT '2004-12-28 00:00:00',
  `a_event_point` tinyint UNSIGNED NOT NULL DEFAULT 5,
  PRIMARY KEY (`a_index`, `a_user_index`) USING BTREE,
  UNIQUE INDEX `a_index`(`a_index`) USING BTREE,
  INDEX `char_index`(`a_good_index`) USING BTREE,
  INDEX `a_user_index`(`a_user_index`, `a_week_index`) USING BTREE
) ENGINE = MyISAM AUTO_INCREMENT = 1 CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Records of t_event
-- ----------------------------

-- ----------------------------
-- Table structure for t_event_gomdori_count
-- ----------------------------
DROP TABLE IF EXISTS `t_event_gomdori_count`;
CREATE TABLE `t_event_gomdori_count`  (
  `a_server` int NOT NULL DEFAULT 0,
  `a_count` int NOT NULL DEFAULT 0,
  `a_updatedate` datetime(0) NOT NULL,
  PRIMARY KEY (`a_server`) USING BTREE
) ENGINE = MyISAM CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Fixed;

-- ----------------------------
-- Records of t_event_gomdori_count
-- ----------------------------
INSERT INTO `t_event_gomdori_count` VALUES (1, 0, '2022-10-04 19:48:56');

-- ----------------------------
-- Table structure for t_event_usercomeback
-- ----------------------------
DROP TABLE IF EXISTS `t_event_usercomeback`;
CREATE TABLE `t_event_usercomeback`  (
  `a_user_idx` int UNSIGNED NOT NULL DEFAULT 0,
  `a_server_num` tinyint UNSIGNED NULL DEFAULT 0,
  `a_char_idx` int UNSIGNED NULL DEFAULT 0,
  `a_gift_date` datetime(0) NOT NULL,
  PRIMARY KEY (`a_user_idx`) USING BTREE,
  UNIQUE INDEX `a_user_idx`(`a_user_idx`) USING BTREE
) ENGINE = MyISAM CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Fixed;

-- ----------------------------
-- Records of t_event_usercomeback
-- ----------------------------

-- ----------------------------
-- Table structure for t_event_xmastree_point
-- ----------------------------
DROP TABLE IF EXISTS `t_event_xmastree_point`;
CREATE TABLE `t_event_xmastree_point`  (
  `a_server` int NOT NULL DEFAULT 0,
  `a_point` int UNSIGNED NOT NULL DEFAULT 0,
  `a_lastupdate` datetime(0) NOT NULL,
  PRIMARY KEY (`a_server`) USING BTREE
) ENGINE = MyISAM CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Fixed;

-- ----------------------------
-- Records of t_event_xmastree_point
-- ----------------------------
INSERT INTO `t_event_xmastree_point` VALUES (1, 0, '2022-10-04 19:48:56');

-- ----------------------------
-- Table structure for t_gift00
-- ----------------------------
DROP TABLE IF EXISTS `t_gift00`;
CREATE TABLE `t_gift00`  (
  `a_index` int NOT NULL AUTO_INCREMENT,
  `a_server` int NOT NULL DEFAULT 0,
  `a_send_user_idx` int NOT NULL DEFAULT 0,
  `a_send_char_name` varchar(50) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL DEFAULT '',
  `a_send_msg` varchar(100) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL DEFAULT '',
  `a_recv_user_idx` int NOT NULL DEFAULT 0,
  `a_recv_char_name` varchar(50) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL DEFAULT '',
  `a_send_date` datetime(0) NOT NULL,
  `a_ctid` int NOT NULL DEFAULT -1,
  `a_use_date` datetime(0) NOT NULL,
  `a_use_char_idx` int NOT NULL DEFAULT 0,
  PRIMARY KEY (`a_index`) USING BTREE,
  INDEX `idx_sender`(`a_send_user_idx`, `a_send_date`) USING BTREE,
  INDEX `idx_recv`(`a_recv_user_idx`, `a_send_date`) USING BTREE
) ENGINE = InnoDB AUTO_INCREMENT = 1 CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Records of t_gift00
-- ----------------------------

-- ----------------------------
-- Table structure for t_gift01
-- ----------------------------
DROP TABLE IF EXISTS `t_gift01`;
CREATE TABLE `t_gift01`  (
  `a_index` int NOT NULL AUTO_INCREMENT,
  `a_server` int NOT NULL DEFAULT 0,
  `a_send_user_idx` int NOT NULL DEFAULT 0,
  `a_send_char_name` varchar(50) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL DEFAULT '',
  `a_send_msg` varchar(100) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL DEFAULT '',
  `a_recv_user_idx` int NOT NULL DEFAULT 0,
  `a_recv_char_name` varchar(50) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL DEFAULT '',
  `a_send_date` datetime(0) NOT NULL,
  `a_ctid` int NOT NULL DEFAULT -1,
  `a_use_date` datetime(0) NOT NULL,
  `a_use_char_idx` int NOT NULL DEFAULT 0,
  PRIMARY KEY (`a_index`) USING BTREE,
  INDEX `idx_sender`(`a_send_user_idx`, `a_send_date`) USING BTREE,
  INDEX `idx_recv`(`a_recv_user_idx`, `a_send_date`) USING BTREE
) ENGINE = InnoDB AUTO_INCREMENT = 1 CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Records of t_gift01
-- ----------------------------

-- ----------------------------
-- Table structure for t_gift02
-- ----------------------------
DROP TABLE IF EXISTS `t_gift02`;
CREATE TABLE `t_gift02`  (
  `a_index` int NOT NULL AUTO_INCREMENT,
  `a_server` int NOT NULL DEFAULT 0,
  `a_send_user_idx` int NOT NULL DEFAULT 0,
  `a_send_char_name` varchar(50) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL DEFAULT '',
  `a_send_msg` varchar(100) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL DEFAULT '',
  `a_recv_user_idx` int NOT NULL DEFAULT 0,
  `a_recv_char_name` varchar(50) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL DEFAULT '',
  `a_send_date` datetime(0) NOT NULL,
  `a_ctid` int NOT NULL DEFAULT -1,
  `a_use_date` datetime(0) NOT NULL,
  `a_use_char_idx` int NOT NULL DEFAULT 0,
  PRIMARY KEY (`a_index`) USING BTREE,
  INDEX `idx_sender`(`a_send_user_idx`, `a_send_date`) USING BTREE,
  INDEX `idx_recv`(`a_recv_user_idx`, `a_send_date`) USING BTREE
) ENGINE = InnoDB AUTO_INCREMENT = 1 CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Records of t_gift02
-- ----------------------------

-- ----------------------------
-- Table structure for t_gift03
-- ----------------------------
DROP TABLE IF EXISTS `t_gift03`;
CREATE TABLE `t_gift03`  (
  `a_index` int NOT NULL AUTO_INCREMENT,
  `a_server` int NOT NULL DEFAULT 0,
  `a_send_user_idx` int NOT NULL DEFAULT 0,
  `a_send_char_name` varchar(50) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL DEFAULT '',
  `a_send_msg` varchar(100) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL DEFAULT '',
  `a_recv_user_idx` int NOT NULL DEFAULT 0,
  `a_recv_char_name` varchar(50) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL DEFAULT '',
  `a_send_date` datetime(0) NOT NULL,
  `a_ctid` int NOT NULL DEFAULT -1,
  `a_use_date` datetime(0) NOT NULL,
  `a_use_char_idx` int NOT NULL DEFAULT 0,
  PRIMARY KEY (`a_index`) USING BTREE,
  INDEX `idx_sender`(`a_send_user_idx`, `a_send_date`) USING BTREE,
  INDEX `idx_recv`(`a_recv_user_idx`, `a_send_date`) USING BTREE
) ENGINE = InnoDB AUTO_INCREMENT = 1 CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Records of t_gift03
-- ----------------------------

-- ----------------------------
-- Table structure for t_gift04
-- ----------------------------
DROP TABLE IF EXISTS `t_gift04`;
CREATE TABLE `t_gift04`  (
  `a_index` int NOT NULL AUTO_INCREMENT,
  `a_server` int NOT NULL DEFAULT 0,
  `a_send_user_idx` int NOT NULL DEFAULT 0,
  `a_send_char_name` varchar(50) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL DEFAULT '',
  `a_send_msg` varchar(100) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL DEFAULT '',
  `a_recv_user_idx` int NOT NULL DEFAULT 0,
  `a_recv_char_name` varchar(50) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL DEFAULT '',
  `a_send_date` datetime(0) NOT NULL,
  `a_ctid` int NOT NULL DEFAULT -1,
  `a_use_date` datetime(0) NOT NULL,
  `a_use_char_idx` int NOT NULL DEFAULT 0,
  PRIMARY KEY (`a_index`) USING BTREE,
  INDEX `idx_sender`(`a_send_user_idx`, `a_send_date`) USING BTREE,
  INDEX `idx_recv`(`a_recv_user_idx`, `a_send_date`) USING BTREE
) ENGINE = InnoDB AUTO_INCREMENT = 1 CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Records of t_gift04
-- ----------------------------

-- ----------------------------
-- Table structure for t_gift05
-- ----------------------------
DROP TABLE IF EXISTS `t_gift05`;
CREATE TABLE `t_gift05`  (
  `a_index` int NOT NULL AUTO_INCREMENT,
  `a_server` int NOT NULL DEFAULT 0,
  `a_send_user_idx` int NOT NULL DEFAULT 0,
  `a_send_char_name` varchar(50) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL DEFAULT '',
  `a_send_msg` varchar(100) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL DEFAULT '',
  `a_recv_user_idx` int NOT NULL DEFAULT 0,
  `a_recv_char_name` varchar(50) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL DEFAULT '',
  `a_send_date` datetime(0) NOT NULL,
  `a_ctid` int NOT NULL DEFAULT -1,
  `a_use_date` datetime(0) NOT NULL,
  `a_use_char_idx` int NOT NULL DEFAULT 0,
  PRIMARY KEY (`a_index`) USING BTREE,
  INDEX `idx_sender`(`a_send_user_idx`, `a_send_date`) USING BTREE,
  INDEX `idx_recv`(`a_recv_user_idx`, `a_send_date`) USING BTREE
) ENGINE = InnoDB AUTO_INCREMENT = 1 CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Records of t_gift05
-- ----------------------------

-- ----------------------------
-- Table structure for t_gift06
-- ----------------------------
DROP TABLE IF EXISTS `t_gift06`;
CREATE TABLE `t_gift06`  (
  `a_index` int NOT NULL AUTO_INCREMENT,
  `a_server` int NOT NULL DEFAULT 0,
  `a_send_user_idx` int NOT NULL DEFAULT 0,
  `a_send_char_name` varchar(50) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL DEFAULT '',
  `a_send_msg` varchar(100) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL DEFAULT '',
  `a_recv_user_idx` int NOT NULL DEFAULT 0,
  `a_recv_char_name` varchar(50) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL DEFAULT '',
  `a_send_date` datetime(0) NOT NULL,
  `a_ctid` int NOT NULL DEFAULT -1,
  `a_use_date` datetime(0) NOT NULL,
  `a_use_char_idx` int NOT NULL DEFAULT 0,
  PRIMARY KEY (`a_index`) USING BTREE,
  INDEX `idx_sender`(`a_send_user_idx`, `a_send_date`) USING BTREE,
  INDEX `idx_recv`(`a_recv_user_idx`, `a_send_date`) USING BTREE
) ENGINE = InnoDB AUTO_INCREMENT = 1 CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Records of t_gift06
-- ----------------------------

-- ----------------------------
-- Table structure for t_gift07
-- ----------------------------
DROP TABLE IF EXISTS `t_gift07`;
CREATE TABLE `t_gift07`  (
  `a_index` int NOT NULL AUTO_INCREMENT,
  `a_server` int NOT NULL DEFAULT 0,
  `a_send_user_idx` int NOT NULL DEFAULT 0,
  `a_send_char_name` varchar(50) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL DEFAULT '',
  `a_send_msg` varchar(100) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL DEFAULT '',
  `a_recv_user_idx` int NOT NULL DEFAULT 0,
  `a_recv_char_name` varchar(50) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL DEFAULT '',
  `a_send_date` datetime(0) NOT NULL,
  `a_ctid` int NOT NULL DEFAULT -1,
  `a_use_date` datetime(0) NOT NULL,
  `a_use_char_idx` int NOT NULL DEFAULT 0,
  PRIMARY KEY (`a_index`) USING BTREE,
  INDEX `idx_sender`(`a_send_user_idx`, `a_send_date`) USING BTREE,
  INDEX `idx_recv`(`a_recv_user_idx`, `a_send_date`) USING BTREE
) ENGINE = InnoDB AUTO_INCREMENT = 1 CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Records of t_gift07
-- ----------------------------

-- ----------------------------
-- Table structure for t_gift08
-- ----------------------------
DROP TABLE IF EXISTS `t_gift08`;
CREATE TABLE `t_gift08`  (
  `a_index` int NOT NULL AUTO_INCREMENT,
  `a_server` int NOT NULL DEFAULT 0,
  `a_send_user_idx` int NOT NULL DEFAULT 0,
  `a_send_char_name` varchar(50) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL DEFAULT '',
  `a_send_msg` varchar(100) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL DEFAULT '',
  `a_recv_user_idx` int NOT NULL DEFAULT 0,
  `a_recv_char_name` varchar(50) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL DEFAULT '',
  `a_send_date` datetime(0) NOT NULL,
  `a_ctid` int NOT NULL DEFAULT -1,
  `a_use_date` datetime(0) NOT NULL,
  `a_use_char_idx` int NOT NULL DEFAULT 0,
  PRIMARY KEY (`a_index`) USING BTREE,
  INDEX `idx_sender`(`a_send_user_idx`, `a_send_date`) USING BTREE,
  INDEX `idx_recv`(`a_recv_user_idx`, `a_send_date`) USING BTREE
) ENGINE = InnoDB AUTO_INCREMENT = 1 CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Records of t_gift08
-- ----------------------------

-- ----------------------------
-- Table structure for t_gift09
-- ----------------------------
DROP TABLE IF EXISTS `t_gift09`;
CREATE TABLE `t_gift09`  (
  `a_index` int NOT NULL AUTO_INCREMENT,
  `a_server` int NOT NULL DEFAULT 0,
  `a_send_user_idx` int NOT NULL DEFAULT 0,
  `a_send_char_name` varchar(50) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL DEFAULT '',
  `a_send_msg` varchar(100) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL DEFAULT '',
  `a_recv_user_idx` int NOT NULL DEFAULT 0,
  `a_recv_char_name` varchar(50) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL DEFAULT '',
  `a_send_date` datetime(0) NOT NULL,
  `a_ctid` int NOT NULL DEFAULT -1,
  `a_use_date` datetime(0) NOT NULL,
  `a_use_char_idx` int NOT NULL DEFAULT 0,
  PRIMARY KEY (`a_index`) USING BTREE,
  INDEX `idx_sender`(`a_send_user_idx`, `a_send_date`) USING BTREE,
  INDEX `idx_recv`(`a_recv_user_idx`, `a_send_date`) USING BTREE
) ENGINE = InnoDB AUTO_INCREMENT = 1 CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Records of t_gift09
-- ----------------------------

-- ----------------------------
-- Table structure for t_gmtool_chatmonitor
-- ----------------------------
DROP TABLE IF EXISTS `t_gmtool_chatmonitor`;
CREATE TABLE `t_gmtool_chatmonitor`  (
  `a_index` int NOT NULL AUTO_INCREMENT,
  `a_charindex` int NOT NULL DEFAULT 0,
  `a_server` int NOT NULL DEFAULT 0,
  `a_subno` int NOT NULL DEFAULT 0,
  `a_type` int NOT NULL DEFAULT 0,
  `a_chat` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL DEFAULT '',
  `a_date` datetime(0) NOT NULL,
  PRIMARY KEY (`a_index`, `a_charindex`) USING BTREE
) ENGINE = MyISAM AUTO_INCREMENT = 1 CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Records of t_gmtool_chatmonitor
-- ----------------------------

-- ----------------------------
-- Table structure for t_gmtool_chatting
-- ----------------------------
DROP TABLE IF EXISTS `t_gmtool_chatting`;
CREATE TABLE `t_gmtool_chatting`  (
  `a_index` int NOT NULL AUTO_INCREMENT,
  `a_server` int NOT NULL DEFAULT 0,
  `a_sub` int NOT NULL DEFAULT 0,
  `a_gmindex` int NOT NULL DEFAULT 0,
  `a_gmname` varchar(50) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL DEFAULT '',
  `a_charname` varchar(50) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL DEFAULT '',
  `a_chat` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL DEFAULT '',
  `a_date` datetime(0) NOT NULL,
  PRIMARY KEY (`a_index`) USING BTREE
) ENGINE = MyISAM AUTO_INCREMENT = 1 CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Records of t_gmtool_chatting
-- ----------------------------

-- ----------------------------
-- Table structure for t_gmtool_command
-- ----------------------------
DROP TABLE IF EXISTS `t_gmtool_command`;
CREATE TABLE `t_gmtool_command`  (
  `a_index` int NOT NULL AUTO_INCREMENT,
  `a_gmindex` int NOT NULL DEFAULT 0,
  `a_gmname` varchar(50) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL DEFAULT '',
  `a_date` datetime(0) NOT NULL,
  `a_gmcommand` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL DEFAULT '',
  PRIMARY KEY (`a_index`) USING BTREE
) ENGINE = MyISAM AUTO_INCREMENT = 1 CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Records of t_gmtool_command
-- ----------------------------

-- ----------------------------
-- Table structure for t_ip_block
-- ----------------------------
DROP TABLE IF EXISTS `t_ip_block`;
CREATE TABLE `t_ip_block`  (
  `a_index` int NOT NULL AUTO_INCREMENT,
  `a_ip` varchar(50) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
  PRIMARY KEY (`a_index`) USING BTREE,
  UNIQUE INDEX `a_index`(`a_index`, `a_ip`) USING BTREE,
  INDEX `a_index_2`(`a_index`, `a_ip`) USING BTREE
) ENGINE = MyISAM AUTO_INCREMENT = 1 CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Records of t_ip_block
-- ----------------------------

-- ----------------------------
-- Table structure for t_ip_log
-- ----------------------------
DROP TABLE IF EXISTS `t_ip_log`;
CREATE TABLE `t_ip_log`  (
  `a_index` int UNSIGNED NOT NULL AUTO_INCREMENT,
  `a_ip` varchar(20) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL DEFAULT '0',
  `a_date` datetime(0) NOT NULL,
  PRIMARY KEY (`a_index`) USING BTREE
) ENGINE = MyISAM AUTO_INCREMENT = 1 CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Records of t_ip_log
-- ----------------------------

-- ----------------------------
-- Table structure for t_iplist
-- ----------------------------
DROP TABLE IF EXISTS `t_iplist`;
CREATE TABLE `t_iplist`  (
  `a_index` int NOT NULL AUTO_INCREMENT,
  `a_ipstart_N` bigint NOT NULL DEFAULT 0,
  `a_ipend_N` bigint NOT NULL DEFAULT 0,
  `a_nation_S` varchar(50) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL DEFAULT '',
  `a_nationcode` int NOT NULL DEFAULT -1,
  PRIMARY KEY (`a_index`) USING BTREE
) ENGINE = MyISAM AUTO_INCREMENT = 1 CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Records of t_iplist
-- ----------------------------

-- ----------------------------
-- Table structure for t_key
-- ----------------------------
DROP TABLE IF EXISTS `t_key`;
CREATE TABLE `t_key`  (
  `a_index` int UNSIGNED NOT NULL AUTO_INCREMENT,
  `a_strkey` varchar(15) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL DEFAULT '000000000000',
  `a_enable` tinyint UNSIGNED NOT NULL DEFAULT 0,
  `a_kind` varchar(30) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL DEFAULT '0',
  `a_use_date` datetime(0) NULL DEFAULT NULL,
  PRIMARY KEY (`a_index`) USING BTREE,
  UNIQUE INDEX `idx_strKey`(`a_strkey`) USING BTREE,
  INDEX `idx_kind`(`a_kind`) USING BTREE
) ENGINE = MyISAM AUTO_INCREMENT = 1 CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Records of t_key
-- ----------------------------

-- ----------------------------
-- Table structure for t_lacarette_log
-- ----------------------------
DROP TABLE IF EXISTS `t_lacarette_log`;
CREATE TABLE `t_lacarette_log`  (
  `a_user_idx` int UNSIGNED NOT NULL DEFAULT 0,
  `a_char_idx` int UNSIGNED NOT NULL DEFAULT 0,
  `a_date` date NULL DEFAULT NULL,
  `a_repeat` int UNSIGNED NOT NULL DEFAULT 0,
  `a_repeat_date` date NOT NULL
) ENGINE = MyISAM CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Fixed;

-- ----------------------------
-- Records of t_lacarette_log
-- ----------------------------

-- ----------------------------
-- Table structure for t_manage_db
-- ----------------------------
DROP TABLE IF EXISTS `t_manage_db`;
CREATE TABLE `t_manage_db`  (
  `a_index` int NOT NULL AUTO_INCREMENT,
  `a_type` enum('DATA','CHAR') CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL DEFAULT 'CHAR',
  `a_enable` tinyint NOT NULL DEFAULT 1,
  `a_name` varchar(20) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL DEFAULT '',
  `a_db_ip` varchar(16) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL DEFAULT '',
  `a_db_id` varchar(20) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL DEFAULT '',
  `a_db_pw` varchar(20) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL DEFAULT '',
  `a_db_name` varchar(20) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL DEFAULT '',
  PRIMARY KEY (`a_index`) USING BTREE
) ENGINE = MyISAM AUTO_INCREMENT = 1 CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Records of t_manage_db
-- ----------------------------

-- ----------------------------
-- Table structure for t_manage_log
-- ----------------------------
DROP TABLE IF EXISTS `t_manage_log`;
CREATE TABLE `t_manage_log`  (
  `a_index` int NOT NULL AUTO_INCREMENT,
  `a_master_idx` int NOT NULL DEFAULT 0,
  `a_date` datetime(0) NOT NULL,
  `a_server` varchar(20) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL DEFAULT '',
  `a_char_idx` int NOT NULL DEFAULT 0,
  `a_user_idx` int NOT NULL DEFAULT 0,
  `a_comment` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL DEFAULT '',
  PRIMARY KEY (`a_index`) USING BTREE,
  INDEX `a_idname`(`a_master_idx`) USING BTREE
) ENGINE = MyISAM AUTO_INCREMENT = 1 CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Records of t_manage_log
-- ----------------------------

-- ----------------------------
-- Table structure for t_manage_users
-- ----------------------------
DROP TABLE IF EXISTS `t_manage_users`;
CREATE TABLE `t_manage_users`  (
  `a_index` int NOT NULL AUTO_INCREMENT,
  `a_idname` varchar(30) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL DEFAULT '',
  `a_passwd` varchar(15) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL DEFAULT '',
  `a_enable` int UNSIGNED NULL DEFAULT 1,
  `a_master` enum('N','Y') CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL DEFAULT 'N',
  `a_recent` datetime(0) NOT NULL,
  `a_login` tinyint NOT NULL DEFAULT 0,
  `a_serial_code` char(1) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL DEFAULT '',
  `a_serial_num` int NOT NULL DEFAULT 0,
  PRIMARY KEY (`a_index`) USING BTREE,
  UNIQUE INDEX `a_idname`(`a_idname`) USING BTREE,
  INDEX `a_passwd`(`a_passwd`) USING BTREE
) ENGINE = MyISAM AUTO_INCREMENT = 1 CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Records of t_manage_users
-- ----------------------------

-- ----------------------------
-- Table structure for t_new_promoitem
-- ----------------------------
DROP TABLE IF EXISTS `t_new_promoitem`;
CREATE TABLE `t_new_promoitem`  (
  `a_index` int NOT NULL AUTO_INCREMENT,
  `a_section_type` int NOT NULL DEFAULT 0,
  `a_item_idx` int NOT NULL DEFAULT 0,
  `a_item_count` int NOT NULL DEFAULT 0,
  `a_item_plus` int NOT NULL DEFAULT 0,
  `a_item_flag` int NOT NULL DEFAULT 0,
  PRIMARY KEY (`a_index`, `a_section_type`) USING BTREE
) ENGINE = MyISAM AUTO_INCREMENT = 1 CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Fixed;

-- ----------------------------
-- Records of t_new_promoitem
-- ----------------------------

-- ----------------------------
-- Table structure for t_new_promotion
-- ----------------------------
DROP TABLE IF EXISTS `t_new_promotion`;
CREATE TABLE `t_new_promotion`  (
  `a_index` int UNSIGNED NOT NULL AUTO_INCREMENT,
  `a_enable` tinyint NOT NULL DEFAULT 0,
  `a_use_state` tinyint NOT NULL DEFAULT 0,
  `a_section_string` varchar(30) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL DEFAULT '',
  `a_section_type` int NOT NULL DEFAULT 0,
  `a_start_date` datetime(0) NOT NULL,
  `a_end_date` datetime(0) NOT NULL,
  `a_use_date` datetime(0) NOT NULL,
  `a_key_string` varchar(20) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL DEFAULT '',
  PRIMARY KEY (`a_index`, `a_section_type`) USING BTREE
) ENGINE = MyISAM AUTO_INCREMENT = 1 CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Records of t_new_promotion
-- ----------------------------

-- ----------------------------
-- Table structure for t_pcbang_2nd
-- ----------------------------
DROP TABLE IF EXISTS `t_pcbang_2nd`;
CREATE TABLE `t_pcbang_2nd`  (
  `a_index` int UNSIGNED NOT NULL AUTO_INCREMENT,
  `a_enable` tinyint NOT NULL DEFAULT 0,
  `a_ip` varchar(50) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL DEFAULT '',
  PRIMARY KEY (`a_index`) USING BTREE,
  UNIQUE INDEX `a_ip`(`a_ip`) USING BTREE
) ENGINE = MyISAM AUTO_INCREMENT = 1 CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Records of t_pcbang_2nd
-- ----------------------------

-- ----------------------------
-- Table structure for t_pcbang_log
-- ----------------------------
DROP TABLE IF EXISTS `t_pcbang_log`;
CREATE TABLE `t_pcbang_log`  (
  `a_user_idx` int UNSIGNED NOT NULL DEFAULT 0,
  `a_ip` varchar(16) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL DEFAULT '',
  `a_action` tinyint NOT NULL DEFAULT 0,
  `a_update` datetime(0) NOT NULL
) ENGINE = MyISAM CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Records of t_pcbang_log
-- ----------------------------

-- ----------------------------
-- Table structure for t_promotion2_key
-- ----------------------------
DROP TABLE IF EXISTS `t_promotion2_key`;
CREATE TABLE `t_promotion2_key`  (
  `a_index` int UNSIGNED NOT NULL AUTO_INCREMENT,
  `a_strKey` varchar(25) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL DEFAULT '0',
  `a_user_idx` int UNSIGNED NOT NULL DEFAULT 0,
  `a_enable` tinyint UNSIGNED NOT NULL DEFAULT 1,
  `a_kind` tinyint UNSIGNED NOT NULL DEFAULT 0,
  `a_use_char_idx` int UNSIGNED NOT NULL DEFAULT 0,
  `a_use_date` datetime(0) NOT NULL,
  PRIMARY KEY (`a_index`, `a_strKey`) USING BTREE,
  UNIQUE INDEX `a_strKey`(`a_strKey`) USING BTREE
) ENGINE = MyISAM AUTO_INCREMENT = 1 CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Records of t_promotion2_key
-- ----------------------------

-- ----------------------------
-- Table structure for t_purchase00
-- ----------------------------
DROP TABLE IF EXISTS `t_purchase00`;
CREATE TABLE `t_purchase00`  (
  `a_index` int NOT NULL AUTO_INCREMENT,
  `a_user_idx` int NOT NULL DEFAULT 0,
  `a_server` tinyint UNSIGNED NOT NULL DEFAULT 0,
  `a_ctid` int NOT NULL DEFAULT 0,
  `a_serial` int NOT NULL DEFAULT 0,
  `a_pdate` datetime(0) NOT NULL,
  `a_confirm` tinyint UNSIGNED NULL DEFAULT 0,
  `a_use_char_idx` int NOT NULL DEFAULT 0,
  `a_use_date` datetime(0) NOT NULL,
  `a_ip` varchar(30) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
  PRIMARY KEY (`a_index`) USING BTREE,
  INDEX `a_ctid`(`a_ctid`, `a_serial`, `a_pdate`) USING BTREE,
  INDEX `idx_use`(`a_use_char_idx`, `a_server`) USING BTREE
) ENGINE = InnoDB AUTO_INCREMENT = 1 CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Records of t_purchase00
-- ----------------------------

-- ----------------------------
-- Table structure for t_purchase01
-- ----------------------------
DROP TABLE IF EXISTS `t_purchase01`;
CREATE TABLE `t_purchase01`  (
  `a_index` int NOT NULL AUTO_INCREMENT,
  `a_user_idx` int NOT NULL DEFAULT 0,
  `a_server` tinyint UNSIGNED NOT NULL DEFAULT 0,
  `a_ctid` int NOT NULL DEFAULT 0,
  `a_serial` int NOT NULL DEFAULT 0,
  `a_pdate` datetime(0) NOT NULL,
  `a_confirm` tinyint UNSIGNED NULL DEFAULT 0,
  `a_use_char_idx` int NOT NULL DEFAULT 0,
  `a_use_date` datetime(0) NOT NULL,
  `a_ip` varchar(30) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
  `a_coupon_id` int NULL DEFAULT -1,
  PRIMARY KEY (`a_index`) USING BTREE,
  INDEX `a_ctid`(`a_ctid`, `a_serial`, `a_pdate`) USING BTREE,
  INDEX `idx_use`(`a_use_char_idx`, `a_server`) USING BTREE
) ENGINE = InnoDB AUTO_INCREMENT = 1 CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Records of t_purchase01
-- ----------------------------

-- ----------------------------
-- Table structure for t_purchase02
-- ----------------------------
DROP TABLE IF EXISTS `t_purchase02`;
CREATE TABLE `t_purchase02`  (
  `a_index` int NOT NULL AUTO_INCREMENT,
  `a_user_idx` int NOT NULL DEFAULT 0,
  `a_server` tinyint UNSIGNED NOT NULL DEFAULT 0,
  `a_ctid` int NOT NULL DEFAULT 0,
  `a_serial` int NOT NULL DEFAULT 0,
  `a_pdate` datetime(0) NOT NULL,
  `a_confirm` tinyint UNSIGNED NULL DEFAULT 0,
  `a_use_char_idx` int NOT NULL DEFAULT 0,
  `a_use_date` datetime(0) NOT NULL,
  `a_ip` varchar(30) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
  `a_coupon_id` int NULL DEFAULT -1,
  PRIMARY KEY (`a_index`) USING BTREE,
  INDEX `a_ctid`(`a_ctid`, `a_serial`, `a_pdate`) USING BTREE,
  INDEX `idx_use`(`a_use_char_idx`, `a_server`) USING BTREE
) ENGINE = InnoDB AUTO_INCREMENT = 1 CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Records of t_purchase02
-- ----------------------------

-- ----------------------------
-- Table structure for t_purchase03
-- ----------------------------
DROP TABLE IF EXISTS `t_purchase03`;
CREATE TABLE `t_purchase03`  (
  `a_index` int NOT NULL AUTO_INCREMENT,
  `a_user_idx` int NOT NULL DEFAULT 0,
  `a_server` tinyint UNSIGNED NOT NULL DEFAULT 0,
  `a_ctid` int NOT NULL DEFAULT 0,
  `a_serial` int NOT NULL DEFAULT 0,
  `a_pdate` datetime(0) NOT NULL,
  `a_confirm` tinyint UNSIGNED NULL DEFAULT 0,
  `a_use_char_idx` int NOT NULL DEFAULT 0,
  `a_use_date` datetime(0) NOT NULL,
  `a_ip` varchar(30) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
  `a_coupon_id` int NULL DEFAULT -1,
  PRIMARY KEY (`a_index`) USING BTREE,
  INDEX `a_ctid`(`a_ctid`, `a_serial`, `a_pdate`) USING BTREE,
  INDEX `idx_use`(`a_use_char_idx`, `a_server`) USING BTREE
) ENGINE = InnoDB AUTO_INCREMENT = 1 CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Records of t_purchase03
-- ----------------------------

-- ----------------------------
-- Table structure for t_purchase04
-- ----------------------------
DROP TABLE IF EXISTS `t_purchase04`;
CREATE TABLE `t_purchase04`  (
  `a_index` int NOT NULL AUTO_INCREMENT,
  `a_user_idx` int NOT NULL DEFAULT 0,
  `a_server` tinyint UNSIGNED NOT NULL DEFAULT 0,
  `a_ctid` int NOT NULL DEFAULT 0,
  `a_serial` int NOT NULL DEFAULT 0,
  `a_pdate` datetime(0) NOT NULL,
  `a_confirm` tinyint UNSIGNED NULL DEFAULT 0,
  `a_use_char_idx` int NOT NULL DEFAULT 0,
  `a_use_date` datetime(0) NOT NULL,
  `a_ip` varchar(30) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
  `a_coupon_id` int NULL DEFAULT -1,
  PRIMARY KEY (`a_index`) USING BTREE,
  INDEX `a_ctid`(`a_ctid`, `a_serial`, `a_pdate`) USING BTREE,
  INDEX `idx_use`(`a_use_char_idx`, `a_server`) USING BTREE
) ENGINE = InnoDB AUTO_INCREMENT = 1 CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Records of t_purchase04
-- ----------------------------

-- ----------------------------
-- Table structure for t_purchase05
-- ----------------------------
DROP TABLE IF EXISTS `t_purchase05`;
CREATE TABLE `t_purchase05`  (
  `a_index` int NOT NULL AUTO_INCREMENT,
  `a_user_idx` int NOT NULL DEFAULT 0,
  `a_server` tinyint UNSIGNED NOT NULL DEFAULT 0,
  `a_ctid` int NOT NULL DEFAULT 0,
  `a_serial` int NOT NULL DEFAULT 0,
  `a_pdate` datetime(0) NOT NULL,
  `a_confirm` tinyint UNSIGNED NULL DEFAULT 0,
  `a_use_char_idx` int NOT NULL DEFAULT 0,
  `a_use_date` datetime(0) NOT NULL,
  `a_ip` varchar(30) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
  `a_coupon_id` int NULL DEFAULT -1,
  PRIMARY KEY (`a_index`) USING BTREE,
  INDEX `a_ctid`(`a_ctid`, `a_serial`, `a_pdate`) USING BTREE,
  INDEX `idx_use`(`a_use_char_idx`, `a_server`) USING BTREE
) ENGINE = InnoDB AUTO_INCREMENT = 1 CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Records of t_purchase05
-- ----------------------------

-- ----------------------------
-- Table structure for t_purchase06
-- ----------------------------
DROP TABLE IF EXISTS `t_purchase06`;
CREATE TABLE `t_purchase06`  (
  `a_index` int NOT NULL AUTO_INCREMENT,
  `a_user_idx` int NOT NULL DEFAULT 0,
  `a_server` tinyint UNSIGNED NOT NULL DEFAULT 0,
  `a_ctid` int NOT NULL DEFAULT 0,
  `a_serial` int NOT NULL DEFAULT 0,
  `a_pdate` datetime(0) NOT NULL,
  `a_confirm` tinyint UNSIGNED NULL DEFAULT 0,
  `a_use_char_idx` int NOT NULL DEFAULT 0,
  `a_use_date` datetime(0) NOT NULL,
  `a_ip` varchar(30) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
  `a_coupon_id` int NULL DEFAULT -1,
  PRIMARY KEY (`a_index`) USING BTREE,
  INDEX `a_ctid`(`a_ctid`, `a_serial`, `a_pdate`) USING BTREE,
  INDEX `idx_use`(`a_use_char_idx`, `a_server`) USING BTREE
) ENGINE = InnoDB AUTO_INCREMENT = 1 CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Records of t_purchase06
-- ----------------------------

-- ----------------------------
-- Table structure for t_purchase07
-- ----------------------------
DROP TABLE IF EXISTS `t_purchase07`;
CREATE TABLE `t_purchase07`  (
  `a_index` int NOT NULL AUTO_INCREMENT,
  `a_user_idx` int NOT NULL DEFAULT 0,
  `a_server` tinyint UNSIGNED NOT NULL DEFAULT 0,
  `a_ctid` int NOT NULL DEFAULT 0,
  `a_serial` int NOT NULL DEFAULT 0,
  `a_pdate` datetime(0) NOT NULL,
  `a_confirm` tinyint UNSIGNED NULL DEFAULT 0,
  `a_use_char_idx` int NOT NULL DEFAULT 0,
  `a_use_date` datetime(0) NOT NULL,
  `a_ip` varchar(30) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
  `a_coupon_id` int NULL DEFAULT -1,
  PRIMARY KEY (`a_index`) USING BTREE,
  INDEX `a_ctid`(`a_ctid`, `a_serial`, `a_pdate`) USING BTREE,
  INDEX `idx_use`(`a_use_char_idx`, `a_server`) USING BTREE
) ENGINE = InnoDB AUTO_INCREMENT = 1 CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Records of t_purchase07
-- ----------------------------

-- ----------------------------
-- Table structure for t_purchase08
-- ----------------------------
DROP TABLE IF EXISTS `t_purchase08`;
CREATE TABLE `t_purchase08`  (
  `a_index` int NOT NULL AUTO_INCREMENT,
  `a_user_idx` int NOT NULL DEFAULT 0,
  `a_server` tinyint UNSIGNED NOT NULL DEFAULT 0,
  `a_ctid` int NOT NULL DEFAULT 0,
  `a_serial` int NOT NULL DEFAULT 0,
  `a_pdate` datetime(0) NOT NULL,
  `a_confirm` tinyint UNSIGNED NULL DEFAULT 0,
  `a_use_char_idx` int NOT NULL DEFAULT 0,
  `a_use_date` datetime(0) NOT NULL,
  `a_ip` varchar(30) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
  `a_coupon_id` int NULL DEFAULT -1,
  PRIMARY KEY (`a_index`) USING BTREE,
  INDEX `a_ctid`(`a_ctid`, `a_serial`, `a_pdate`) USING BTREE,
  INDEX `idx_use`(`a_use_char_idx`, `a_server`) USING BTREE
) ENGINE = InnoDB AUTO_INCREMENT = 1 CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Records of t_purchase08
-- ----------------------------

-- ----------------------------
-- Table structure for t_purchase09
-- ----------------------------
DROP TABLE IF EXISTS `t_purchase09`;
CREATE TABLE `t_purchase09`  (
  `a_index` int NOT NULL AUTO_INCREMENT,
  `a_user_idx` int NOT NULL DEFAULT 0,
  `a_server` tinyint UNSIGNED NOT NULL DEFAULT 0,
  `a_ctid` int NOT NULL DEFAULT 0,
  `a_serial` int NOT NULL DEFAULT 0,
  `a_pdate` datetime(0) NOT NULL,
  `a_confirm` tinyint UNSIGNED NULL DEFAULT 0,
  `a_use_char_idx` int NOT NULL DEFAULT 0,
  `a_use_date` datetime(0) NOT NULL,
  `a_ip` varchar(30) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
  `a_coupon_id` int NULL DEFAULT -1,
  PRIMARY KEY (`a_index`) USING BTREE,
  INDEX `a_ctid`(`a_ctid`, `a_serial`, `a_pdate`) USING BTREE,
  INDEX `idx_use`(`a_use_char_idx`, `a_server`) USING BTREE
) ENGINE = InnoDB AUTO_INCREMENT = 1 CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Records of t_purchase09
-- ----------------------------

-- ----------------------------
-- Table structure for t_ranking
-- ----------------------------
DROP TABLE IF EXISTS `t_ranking`;
CREATE TABLE `t_ranking`  (
  `a_index` int UNSIGNED NOT NULL AUTO_INCREMENT,
  `a_username` varchar(50) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT '0',
  `a_server` smallint UNSIGNED NOT NULL DEFAULT 0,
  `a_rank` int UNSIGNED NULL DEFAULT 0,
  `a_charindex` int UNSIGNED NULL DEFAULT 0,
  `a_charname` varchar(50) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT '0',
  `a_level` int UNSIGNED NULL DEFAULT 0,
  `a_exp` bigint NULL DEFAULT 0,
  `a_job` tinyint UNSIGNED NULL DEFAULT 0,
  `a_job2` tinyint UNSIGNED NULL DEFAULT 0,
  `a_guildname` varchar(50) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT '0',
  `a_date` datetime(0) NOT NULL,
  PRIMARY KEY (`a_index`) USING BTREE,
  INDEX `a_date`(`a_date`) USING BTREE
) ENGINE = MyISAM AUTO_INCREMENT = 1 CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Records of t_ranking
-- ----------------------------

-- ----------------------------
-- Table structure for t_requital_log
-- ----------------------------
DROP TABLE IF EXISTS `t_requital_log`;
CREATE TABLE `t_requital_log`  (
  `a_index` int UNSIGNED NOT NULL AUTO_INCREMENT,
  `a_user_idx` int UNSIGNED NOT NULL DEFAULT 0,
  `a_user_name` varchar(20) CHARACTER SET utf8 COLLATE utf8_bin NOT NULL DEFAULT '',
  `a_char_idx` int UNSIGNED NOT NULL DEFAULT 0,
  `a_char_name` varchar(20) CHARACTER SET utf8 COLLATE utf8_bin NOT NULL DEFAULT '',
  `a_eventCheck_0` tinyint UNSIGNED NOT NULL DEFAULT 0,
  `a_eventCheck_1` tinyint UNSIGNED NOT NULL DEFAULT 0,
  UNIQUE INDEX `a_index`(`a_index`) USING BTREE,
  INDEX `a_index_2`(`a_index`) USING BTREE
) ENGINE = InnoDB AUTO_INCREMENT = 1 CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Records of t_requital_log
-- ----------------------------

-- ----------------------------
-- Table structure for t_users
-- ----------------------------
DROP TABLE IF EXISTS `t_users`;
CREATE TABLE `t_users`  (
  `a_index` int NOT NULL AUTO_INCREMENT,
  `a_idname` varchar(30) CHARACTER SET utf8 COLLATE utf8_bin NOT NULL DEFAULT '',
  `a_passwd` varchar(15) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL DEFAULT '',
  `a_portal_index` int UNSIGNED NOT NULL DEFAULT 0,
  `a_regi_date` datetime(0) NULL DEFAULT NULL,
  `a_end_date` datetime(0) NULL DEFAULT NULL,
  `a_enable` int UNSIGNED NULL DEFAULT 1,
  `a_server_num` int NOT NULL DEFAULT -1,
  `a_subnum` int NOT NULL DEFAULT -1,
  `a_zone_num` int NOT NULL DEFAULT -1,
  `a_timestamp` int UNSIGNED NULL DEFAULT 0,
  `a_preopen_chk` tinyint NOT NULL DEFAULT 0,
  `a_eventpoint` int NOT NULL DEFAULT 10,
  `a_eventpoint_use` int UNSIGNED NOT NULL DEFAULT 0,
  `a_stash_passwd` varchar(50) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL DEFAULT '',
  `a_stash_sealed` tinyint NOT NULL DEFAULT 0,
  `a_stash_password` varchar(16) CHARACTER SET utf8 COLLATE utf8_bin NOT NULL DEFAULT '',
  `a_pcbang_time` int UNSIGNED NOT NULL DEFAULT 0,
  `a_block_time` int NOT NULL DEFAULT 0,
  `a_fail_count` int NOT NULL DEFAULT 0,
  `a_login_time` int NOT NULL DEFAULT 0,
  `a_restart` int NOT NULL DEFAULT 0,
  `a_lastip` varchar(15) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
  `a_lastnation` char(3) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
  PRIMARY KEY (`a_index`) USING BTREE,
  UNIQUE INDEX `a_idname`(`a_idname`) USING BTREE,
  UNIQUE INDEX `idx_portal_index`(`a_portal_index`) USING BTREE,
  INDEX `a_passwd`(`a_passwd`) USING BTREE,
  INDEX `a_sub_num`(`a_server_num`, `a_subnum`) USING BTREE,
  INDEX `idx_zone_num`(`a_zone_num`) USING BTREE
) ENGINE = MyISAM AUTO_INCREMENT = 3 CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Records of t_users
-- ----------------------------
INSERT INTO `t_users` VALUES (1, 'Aiz491', '', 1, '2022-10-05 14:28:27', '2022-10-05 14:41:24', 1, 1, 1, -1, 1664995184, 0, 10, 0, '', 0, '', 0, 0, 0, 0, 0, '127.0.0.1', NULL);
INSERT INTO `t_users` VALUES (2, 'Nate', '', 2, '2022-10-05 14:31:50', '2022-10-05 14:41:19', 1, 1, 1, -1, 1664995279, 0, 10, 0, '', 0, '', 0, 0, 0, 0, 0, NULL, NULL);

-- ----------------------------
-- Table structure for t_wishlist
-- ----------------------------
DROP TABLE IF EXISTS `t_wishlist`;
CREATE TABLE `t_wishlist`  (
  `a_userindex` int UNSIGNED NOT NULL DEFAULT 0,
  `a_ctids` varchar(65) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
  PRIMARY KEY (`a_userindex`) USING BTREE
) ENGINE = MyISAM CHARACTER SET = utf8 COLLATE = utf8_general_ci COMMENT = 'cash shop wish list (소망상자)' ROW_FORMAT = Dynamic;

-- ----------------------------
-- Records of t_wishlist
-- ----------------------------

SET FOREIGN_KEY_CHECKS = 1;
