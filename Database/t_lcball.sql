/*
 Navicat Premium Data Transfer

 Source Server         : local
 Source Server Type    : MySQL
 Source Server Version : 100422
 Source Host           : localhost:3306
 Source Schema         : lc_db

 Target Server Type    : MySQL
 Target Server Version : 100422
 File Encoding         : 65001

 Date: 06/10/2022 16:12:24
*/

SET NAMES utf8mb4;
SET FOREIGN_KEY_CHECKS = 0;

-- ----------------------------
-- Table structure for t_lcball
-- ----------------------------
DROP TABLE IF EXISTS `t_lcball`;
CREATE TABLE `t_lcball`  (
  `a_index` int NOT NULL AUTO_INCREMENT,
  `a_item_order` int NOT NULL DEFAULT 0,
  `a_tocken_index` int NOT NULL DEFAULT 0,
  `a_course_code` tinyint NOT NULL DEFAULT 0,
  `a_order` tinyint NOT NULL DEFAULT 0,
  `a_item_index` int NOT NULL DEFAULT 0,
  `a_item_count` int UNSIGNED NOT NULL DEFAULT 1,
  `a_item_max` int UNSIGNED NOT NULL DEFAULT 0,
  `a_item_remain` int UNSIGNED NOT NULL DEFAULT 0,
  PRIMARY KEY (`a_index`) USING BTREE,
  INDEX `Index`(`a_course_code`, `a_tocken_index`) USING BTREE
) ENGINE = InnoDB AUTO_INCREMENT = 119 CHARACTER SET = latin1 COLLATE = latin1_swedish_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Records of t_lcball
-- ----------------------------
INSERT INTO `t_lcball` VALUES (51, 0, 5123, 0, 0, 4712, 2, 1, 1);
INSERT INTO `t_lcball` VALUES (52, 0, 5123, 0, 1, 1297, 1, 20, 20);
INSERT INTO `t_lcball` VALUES (53, 0, 5123, 0, 2, 2874, 1, 50, 48);
INSERT INTO `t_lcball` VALUES (54, 0, 5123, 0, 3, 882, 3, 300, 275);
INSERT INTO `t_lcball` VALUES (55, 0, 5123, 0, 4, 884, 2, 500, 462);
INSERT INTO `t_lcball` VALUES (56, 0, 5123, 1, 0, 9931, 5, 1, 1);
INSERT INTO `t_lcball` VALUES (57, 0, 5123, 1, 1, 9930, 1, 20, 20);
INSERT INTO `t_lcball` VALUES (58, 0, 5123, 1, 2, 5124, 2, 50, 50);
INSERT INTO `t_lcball` VALUES (59, 0, 5123, 1, 3, 9929, 1, 300, 300);
INSERT INTO `t_lcball` VALUES (60, 0, 5123, 1, 4, 9928, 2, 500, 500);
INSERT INTO `t_lcball` VALUES (61, 0, 5123, 2, 0, 12427, 3, 1, 1);
INSERT INTO `t_lcball` VALUES (62, 0, 5123, 2, 1, 2141, 1, 20, 20);
INSERT INTO `t_lcball` VALUES (63, 0, 5123, 2, 2, 885, 15, 50, 50);
INSERT INTO `t_lcball` VALUES (64, 0, 5123, 2, 3, 971, 1, 300, 300);
INSERT INTO `t_lcball` VALUES (65, 0, 5123, 2, 4, 972, 1, 500, 500);
INSERT INTO `t_lcball` VALUES (67, 0, 6939, 0, 0, 5123, 5, 1, 1);
INSERT INTO `t_lcball` VALUES (68, 0, 6939, 0, 1, 11345, 2, 20, 20);
INSERT INTO `t_lcball` VALUES (69, 0, 6939, 0, 2, 973, 1, 300, 296);
INSERT INTO `t_lcball` VALUES (70, 0, 6939, 0, 3, 2354, 1, 300, 298);
INSERT INTO `t_lcball` VALUES (71, 0, 6939, 0, 4, 2353, 1, 500, 499);
INSERT INTO `t_lcball` VALUES (72, 0, 6939, 1, 0, 9189, 1, 1, 1);
INSERT INTO `t_lcball` VALUES (73, 0, 6939, 1, 1, 2713, 35, 300, 300);
INSERT INTO `t_lcball` VALUES (74, 0, 6939, 1, 2, 227, 35, 300, 300);
INSERT INTO `t_lcball` VALUES (75, 0, 6939, 1, 3, 116, 35, 300, 300);
INSERT INTO `t_lcball` VALUES (76, 0, 6939, 1, 4, 398, 35, 300, 300);
INSERT INTO `t_lcball` VALUES (77, 0, 6939, 2, 0, 5124, 3, 1, 1);
INSERT INTO `t_lcball` VALUES (78, 0, 6939, 2, 1, 1606, 50, 300, 300);
INSERT INTO `t_lcball` VALUES (79, 0, 6939, 2, 2, 3821, 45, 300, 300);
INSERT INTO `t_lcball` VALUES (80, 0, 6939, 2, 3, 773, 35, 300, 300);
INSERT INTO `t_lcball` VALUES (81, 0, 6939, 2, 4, 500, 35, 300, 300);
INSERT INTO `t_lcball` VALUES (82, 0, 5124, 0, 0, 12622, 1, 1, 1);
INSERT INTO `t_lcball` VALUES (83, 0, 5124, 0, 1, 5253, 2, 15, 15);
INSERT INTO `t_lcball` VALUES (84, 0, 5124, 0, 2, 5123, 3, 50, 50);
INSERT INTO `t_lcball` VALUES (85, 0, 5124, 0, 3, 9816, 20, 150, 150);
INSERT INTO `t_lcball` VALUES (86, 0, 5124, 0, 4, 12057, 2, 350, 350);
INSERT INTO `t_lcball` VALUES (87, 0, 5124, 1, 0, 12332, 1, 1, 1);
INSERT INTO `t_lcball` VALUES (88, 0, 5124, 1, 1, 9914, 1, 15, 15);
INSERT INTO `t_lcball` VALUES (89, 0, 5124, 1, 2, 5329, 5, 50, 50);
INSERT INTO `t_lcball` VALUES (90, 0, 5124, 1, 3, 9913, 1, 150, 150);
INSERT INTO `t_lcball` VALUES (91, 0, 5124, 1, 4, 9912, 1, 350, 350);
INSERT INTO `t_lcball` VALUES (92, 0, 5124, 2, 0, 12352, 1, 1, 1);
INSERT INTO `t_lcball` VALUES (93, 0, 5124, 2, 1, 2359, 1, 15, 15);
INSERT INTO `t_lcball` VALUES (94, 0, 5124, 2, 2, 12251, 15, 50, 50);
INSERT INTO `t_lcball` VALUES (95, 0, 5124, 2, 3, 11345, 1, 150, 150);
INSERT INTO `t_lcball` VALUES (96, 0, 5124, 2, 4, 2454, 5, 350, 350);
INSERT INTO `t_lcball` VALUES (97, 0, 12626, 0, 0, 11316, 2, 1, 1);
INSERT INTO `t_lcball` VALUES (98, 0, 12626, 0, 1, 10286, 1, 15, 15);
INSERT INTO `t_lcball` VALUES (99, 0, 12626, 0, 2, 12075, 6, 60, 60);
INSERT INTO `t_lcball` VALUES (100, 0, 12626, 0, 3, 885, 1, 300, 300);
INSERT INTO `t_lcball` VALUES (101, 0, 12626, 0, 4, 12195, 1, 750, 750);
INSERT INTO `t_lcball` VALUES (102, 0, 12626, 1, 0, 12096, 1, 1, 1);
INSERT INTO `t_lcball` VALUES (103, 0, 12626, 1, 1, 12353, 1, 15, 15);
INSERT INTO `t_lcball` VALUES (104, 0, 12626, 1, 2, 12076, 6, 60, 60);
INSERT INTO `t_lcball` VALUES (105, 0, 12626, 1, 3, 5123, 1, 150, 150);
INSERT INTO `t_lcball` VALUES (106, 0, 12626, 1, 4, 2484, 1, 550, 550);
INSERT INTO `t_lcball` VALUES (107, 0, 12626, 2, 0, 12351, 3, 1, 1);
INSERT INTO `t_lcball` VALUES (108, 0, 12626, 2, 1, 12473, 1, 15, 15);
INSERT INTO `t_lcball` VALUES (109, 0, 12626, 2, 2, 2843, 15, 70, 70);
INSERT INTO `t_lcball` VALUES (110, 0, 12626, 2, 3, 5124, 1, 150, 150);
INSERT INTO `t_lcball` VALUES (111, 0, 12626, 2, 4, 12333, 1, 700, 700);
INSERT INTO `t_lcball` VALUES (114, 0, 2146, 0, 0, 882, 100, 100, 100);
INSERT INTO `t_lcball` VALUES (115, 0, 2146, 0, 1, 12342, 1, 5, 5);
INSERT INTO `t_lcball` VALUES (116, 0, 2146, 0, 2, 12622, 2, 100, 100);
INSERT INTO `t_lcball` VALUES (117, 0, 2146, 0, 3, 12090, 1, 4, 4);
INSERT INTO `t_lcball` VALUES (118, 0, 2146, 0, 4, 4919, 10, 300, 300);

SET FOREIGN_KEY_CHECKS = 1;
