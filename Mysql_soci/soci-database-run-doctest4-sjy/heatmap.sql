/*
 Navicat MySQL Data Transfer

 Source Server         : heatmap
 Source Server Type    : MySQL
 Source Server Version : 80033 (8.0.33)
 Source Host           : localhost:3306
 Source Schema         : heatmap

 Target Server Type    : MySQL
 Target Server Version : 80033 (8.0.33)
 File Encoding         : 65001

 Date: 19/08/2023 22:33:09
*/

SET NAMES utf8mb4;
SET FOREIGN_KEY_CHECKS = 0;

-- ----------------------------
-- Table structure for basic_infos
-- ----------------------------
DROP TABLE IF EXISTS `basic_infos`;
CREATE TABLE `basic_infos`  (
  `product_id` int NOT NULL AUTO_INCREMENT COMMENT '产品ID值，主键，自动增加',
  `company_name` varchar(255) CHARACTER SET utf8mb3 COLLATE utf8mb3_general_ci NOT NULL COMMENT '公司名称',
  `project_name` varchar(255) CHARACTER SET utf8mb3 COLLATE utf8mb3_general_ci NOT NULL COMMENT '项目名称',
  `product_name` varchar(255) CHARACTER SET utf8mb3 COLLATE utf8mb3_general_ci NOT NULL COMMENT '产品名称',
  `timestamp` timestamp NOT NULL DEFAULT CURRENT_TIMESTAMP ON UPDATE CURRENT_TIMESTAMP COMMENT '录入产品的时间，例如 2020-10-05 21:16:03',
  PRIMARY KEY (`product_id`) USING BTREE
) ENGINE = InnoDB AUTO_INCREMENT = 3 CHARACTER SET = utf8mb3 COLLATE = utf8mb3_general_ci ROW_FORMAT = DYNAMIC;

-- ----------------------------
-- Table structure for cad_table
-- ----------------------------
DROP TABLE IF EXISTS `cad_table`;
CREATE TABLE `cad_table`  (
  `cad_id` int NOT NULL AUTO_INCREMENT COMMENT 'ID值，自动增加',
  `cam_id` int NOT NULL COMMENT '摄像机ID，0为定模相机，1为动模相机',
  `product_id` int NOT NULL COMMENT '外键，指向basic_infos表的ID值',
  `filepath` varchar(1000) CHARACTER SET utf8mb3 COLLATE utf8mb3_general_ci NULL DEFAULT NULL COMMENT '文件存储路径 2020\\10\\05\\2020-10-05-21-16-00.dxf',
  `timestamp` timestamp NULL DEFAULT CURRENT_TIMESTAMP ON UPDATE CURRENT_TIMESTAMP COMMENT '添加时间，例如 2020-10-05 21:16:03',
  PRIMARY KEY (`cad_id`) USING BTREE,
  INDEX `product_id_fk`(`product_id` ASC) USING BTREE,
  CONSTRAINT `product_id_fk` FOREIGN KEY (`product_id`) REFERENCES `basic_infos` (`product_id`) ON DELETE RESTRICT ON UPDATE CASCADE
) ENGINE = InnoDB AUTO_INCREMENT = 116 CHARACTER SET = utf8mb3 COLLATE = utf8mb3_general_ci ROW_FORMAT = DYNAMIC;

-- ----------------------------
-- Table structure for calibration_configurations
-- ----------------------------
DROP TABLE IF EXISTS `calibration_configurations`;
CREATE TABLE `calibration_configurations`  (
  `calibration_id` int NOT NULL AUTO_INCREMENT,
  `cad_id` int NOT NULL,
  `xpan` float NULL DEFAULT NULL,
  `ypan` float NULL DEFAULT NULL,
  `zoom` float NULL DEFAULT NULL,
  `x` varchar(255) CHARACTER SET utf8mb3 COLLATE utf8mb3_general_ci NULL DEFAULT NULL,
  `y` varchar(255) CHARACTER SET utf8mb3 COLLATE utf8mb3_general_ci NULL DEFAULT NULL,
  `x_offset` varchar(255) CHARACTER SET utf8mb3 COLLATE utf8mb3_general_ci NULL DEFAULT NULL,
  `y_offset` varchar(255) CHARACTER SET utf8mb3 COLLATE utf8mb3_general_ci NULL DEFAULT NULL,
  `timestamp` timestamp NOT NULL DEFAULT CURRENT_TIMESTAMP ON UPDATE CURRENT_TIMESTAMP,
  PRIMARY KEY (`calibration_id`) USING BTREE,
  INDEX `cad_id_fk1`(`cad_id` ASC) USING BTREE,
  CONSTRAINT `cad_id_fk1` FOREIGN KEY (`cad_id`) REFERENCES `cad_table` (`cad_id`) ON DELETE RESTRICT ON UPDATE CASCADE
) ENGINE = InnoDB AUTO_INCREMENT = 5 CHARACTER SET = utf8mb3 COLLATE = utf8mb3_general_ci ROW_FORMAT = DYNAMIC;

-- ----------------------------
-- Table structure for cooling_valve
-- ----------------------------
DROP TABLE IF EXISTS `cooling_valve`;
CREATE TABLE `cooling_valve`  (
  `valve_id` int NOT NULL AUTO_INCREMENT,
  `valve_name` varchar(255) CHARACTER SET utf8mb3 COLLATE utf8mb3_general_ci NOT NULL,
  `valve_type` int NOT NULL,
  `valve_mode` int NOT NULL,
  `temperature_id` int NOT NULL COMMENT '外键',
  `cooling_delay` int NULL DEFAULT NULL,
  `cooling_duration` int NULL DEFAULT NULL,
  `original_cooling_delay` int NULL DEFAULT NULL,
  `original_cooling_duration` int NULL DEFAULT NULL,
  `cooling_blow` int NULL DEFAULT NULL,
  `timestamp` timestamp NOT NULL DEFAULT CURRENT_TIMESTAMP ON UPDATE CURRENT_TIMESTAMP,
  PRIMARY KEY (`valve_id`) USING BTREE,
  INDEX `temperature_id_fk1`(`temperature_id` ASC) USING BTREE,
  CONSTRAINT `temperature_id_fk1` FOREIGN KEY (`temperature_id`) REFERENCES `temperature_bins` (`temperature_id`) ON DELETE RESTRICT ON UPDATE CASCADE
) ENGINE = InnoDB AUTO_INCREMENT = 5709 CHARACTER SET = utf8mb3 COLLATE = utf8mb3_general_ci ROW_FORMAT = DYNAMIC;

-- ----------------------------
-- Table structure for maintenance_record
-- ----------------------------
DROP TABLE IF EXISTS `maintenance_record`;
CREATE TABLE `maintenance_record`  (
  `sql_id` int NOT NULL AUTO_INCREMENT,
  `product_id` int NOT NULL,
  `serial_number` int NULL DEFAULT NULL,
  `date` varchar(255) CHARACTER SET utf8mb3 COLLATE utf8mb3_general_ci NULL DEFAULT NULL,
  `repair_items` varchar(255) CHARACTER SET utf8mb3 COLLATE utf8mb3_general_ci NULL DEFAULT NULL,
  `comments` varchar(255) CHARACTER SET utf8mb3 COLLATE utf8mb3_general_ci NULL DEFAULT NULL,
  `timestamp` timestamp NOT NULL DEFAULT CURRENT_TIMESTAMP ON UPDATE CURRENT_TIMESTAMP,
  PRIMARY KEY (`sql_id`) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8mb3 COLLATE = utf8mb3_general_ci ROW_FORMAT = DYNAMIC;

-- ----------------------------
-- Table structure for measure_intervals
-- ----------------------------
DROP TABLE IF EXISTS `measure_intervals`;
CREATE TABLE `measure_intervals`  (
  `interval_id` int NOT NULL AUTO_INCREMENT,
  `cad_id` int NOT NULL,
  `type` int NULL DEFAULT NULL,
  `after_cooling` tinyint NULL DEFAULT NULL,
  `min` float NOT NULL,
  `max` float NOT NULL,
  `status_id` int NULL DEFAULT NULL,
  `status` varchar(255) CHARACTER SET utf8mb3 COLLATE utf8mb3_general_ci NOT NULL,
  `color` int NULL DEFAULT NULL,
  `interval_group_label` varchar(255) CHARACTER SET utf8mb3 COLLATE utf8mb3_general_ci NULL DEFAULT NULL,
  `cooling_factor` float NULL DEFAULT NULL,
  `timestamp` timestamp NULL DEFAULT CURRENT_TIMESTAMP ON UPDATE CURRENT_TIMESTAMP,
  PRIMARY KEY (`interval_id`) USING BTREE
) ENGINE = InnoDB AUTO_INCREMENT = 309 CHARACTER SET = utf8mb3 COLLATE = utf8mb3_general_ci ROW_FORMAT = DYNAMIC;

-- ----------------------------
-- Table structure for measure_results
-- ----------------------------
DROP TABLE IF EXISTS `measure_results`;
CREATE TABLE `measure_results`  (
  `sql_id` int NOT NULL AUTO_INCREMENT,
  `label` varchar(255) CHARACTER SET utf8mb3 COLLATE utf8mb3_general_ci NOT NULL,
  `number` int NULL DEFAULT NULL,
  `valve_name` varchar(255) CHARACTER SET utf8mb3 COLLATE utf8mb3_general_ci NOT NULL,
  `temperature_id` int NOT NULL,
  `temperature` float NULL DEFAULT NULL,
  `interval_group_label` varchar(255) CHARACTER SET utf8mb3 COLLATE utf8mb3_general_ci NULL DEFAULT NULL,
  `status` varchar(255) CHARACTER SET utf8mb3 COLLATE utf8mb3_general_ci NULL DEFAULT NULL,
  `geometry_id` int NULL DEFAULT NULL,
  `geometry` varchar(255) CHARACTER SET utf8mb3 COLLATE utf8mb3_general_ci NULL DEFAULT NULL,
  `timestamp` timestamp NULL DEFAULT CURRENT_TIMESTAMP ON UPDATE CURRENT_TIMESTAMP,
  PRIMARY KEY (`sql_id`) USING BTREE
) ENGINE = InnoDB AUTO_INCREMENT = 13752 CHARACTER SET = utf8mb3 COLLATE = utf8mb3_general_ci ROW_FORMAT = DYNAMIC;

-- ----------------------------
-- Table structure for mould_infos
-- ----------------------------
DROP TABLE IF EXISTS `mould_infos`;
CREATE TABLE `mould_infos`  (
  `product_id` int NOT NULL,
  `punch_diameter` float NULL DEFAULT NULL,
  `cavity_number` int NULL DEFAULT NULL,
  `al_type` varchar(255) CHARACTER SET utf8mb3 COLLATE utf8mb3_general_ci NULL DEFAULT NULL,
  `al_density` float NULL DEFAULT NULL,
  `casting_temperature` float NULL DEFAULT NULL,
  `cast_weight` float NULL DEFAULT NULL,
  `cast_cinder_vent_weight` float NULL DEFAULT NULL,
  `gate_width` float NULL DEFAULT NULL,
  `gate_thickness` float NULL DEFAULT NULL,
  `mould_material` varchar(255) CHARACTER SET utf8mb3 COLLATE utf8mb3_general_ci NULL DEFAULT '',
  `mould_hardness` float NULL DEFAULT NULL,
  `other` varchar(255) CHARACTER SET utf8mb3 COLLATE utf8mb3_general_ci NULL DEFAULT NULL,
  `timestamp` timestamp NOT NULL DEFAULT CURRENT_TIMESTAMP ON UPDATE CURRENT_TIMESTAMP,
  PRIMARY KEY (`product_id`) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8mb3 COLLATE = utf8mb3_general_ci ROW_FORMAT = DYNAMIC;

-- ----------------------------
-- Table structure for mould_quality
-- ----------------------------
DROP TABLE IF EXISTS `mould_quality`;
CREATE TABLE `mould_quality`  (
  `sql_id` int NOT NULL AUTO_INCREMENT,
  `cad_id` int NULL DEFAULT NULL,
  `serial_number` int NULL DEFAULT NULL,
  `personel` varchar(255) CHARACTER SET utf8mb3 COLLATE utf8mb3_general_ci NULL DEFAULT NULL,
  `date` varchar(255) CHARACTER SET utf8mb3 COLLATE utf8mb3_general_ci NULL DEFAULT NULL,
  `region` varchar(255) CHARACTER SET utf8mb3 COLLATE utf8mb3_general_ci NULL DEFAULT NULL,
  `center_x` float NULL DEFAULT NULL,
  `center_y` float NULL DEFAULT NULL,
  `coordinate` text CHARACTER SET utf8mb3 COLLATE utf8mb3_general_ci NULL,
  `fault_type` varchar(255) CHARACTER SET utf8mb3 COLLATE utf8mb3_general_ci NULL DEFAULT NULL,
  `description` varchar(255) CHARACTER SET utf8mb3 COLLATE utf8mb3_general_ci NULL DEFAULT NULL,
  `timestamp` timestamp NULL DEFAULT CURRENT_TIMESTAMP ON UPDATE CURRENT_TIMESTAMP,
  PRIMARY KEY (`sql_id`) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8mb3 COLLATE = utf8mb3_general_ci ROW_FORMAT = DYNAMIC;

-- ----------------------------
-- Table structure for operation_parameters
-- ----------------------------
DROP TABLE IF EXISTS `operation_parameters`;
CREATE TABLE `operation_parameters`  (
  `operation_id` int NOT NULL AUTO_INCREMENT,
  `product_id` int NOT NULL,
  `serial_number` int NULL DEFAULT NULL,
  `date` varchar(255) CHARACTER SET utf8mb3 COLLATE utf8mb3_general_ci NULL DEFAULT NULL,
  `slow_punch_speed` float NULL DEFAULT NULL,
  `quick_punch_speed` float NULL DEFAULT NULL,
  `cast_force` int NULL DEFAULT NULL,
  `pressure_time` int NULL DEFAULT NULL,
  `clamping_force` int NULL DEFAULT NULL,
  `clotting_time` float NULL DEFAULT NULL,
  `production_cycle` int NULL DEFAULT NULL,
  `high_speed_origin` int NULL DEFAULT NULL,
  `press_distance` int NULL DEFAULT NULL,
  `material_thickness` int NULL DEFAULT NULL,
  `build_pressure_time` int NULL DEFAULT NULL,
  `timestamp` timestamp NOT NULL DEFAULT CURRENT_TIMESTAMP ON UPDATE CURRENT_TIMESTAMP,
  PRIMARY KEY (`operation_id`) USING BTREE
) ENGINE = InnoDB AUTO_INCREMENT = 15 CHARACTER SET = utf8mb3 COLLATE = utf8mb3_general_ci ROW_FORMAT = DYNAMIC;

-- ----------------------------
-- Table structure for product_quality
-- ----------------------------
DROP TABLE IF EXISTS `product_quality`;
CREATE TABLE `product_quality`  (
  `sql_id` int NOT NULL AUTO_INCREMENT,
  `cad_id` int NOT NULL,
  `serial_number` int NULL DEFAULT NULL,
  `region` varchar(255) CHARACTER SET utf8mb3 COLLATE utf8mb3_general_ci NULL DEFAULT NULL,
  `center_x` float NULL DEFAULT NULL,
  `center_y` float NULL DEFAULT NULL,
  `coordinate` text CHARACTER SET utf8mb3 COLLATE utf8mb3_general_ci NULL,
  `fault_type` varchar(255) CHARACTER SET utf8mb3 COLLATE utf8mb3_general_ci NULL DEFAULT NULL,
  `description` varchar(255) CHARACTER SET utf8mb3 COLLATE utf8mb3_general_ci NULL DEFAULT NULL,
  `personel` varchar(255) CHARACTER SET utf8mb3 COLLATE utf8mb3_general_ci NULL DEFAULT NULL,
  `date` varchar(255) CHARACTER SET utf8mb3 COLLATE utf8mb3_general_ci NULL DEFAULT NULL,
  `yield_rate` varchar(255) CHARACTER SET utf8mb3 COLLATE utf8mb3_general_ci NULL DEFAULT NULL,
  `timestamp` timestamp NULL DEFAULT CURRENT_TIMESTAMP ON UPDATE CURRENT_TIMESTAMP,
  PRIMARY KEY (`sql_id`) USING BTREE,
  INDEX `cad_id`(`cad_id` ASC) USING BTREE,
  CONSTRAINT `cad_id` FOREIGN KEY (`cad_id`) REFERENCES `cad_table` (`cad_id`) ON DELETE RESTRICT ON UPDATE CASCADE
) ENGINE = InnoDB CHARACTER SET = utf8mb3 COLLATE = utf8mb3_general_ci ROW_FORMAT = DYNAMIC;

-- ----------------------------
-- Table structure for temperature_bins
-- ----------------------------
DROP TABLE IF EXISTS `temperature_bins`;
CREATE TABLE `temperature_bins`  (
  `temperature_id` int NOT NULL AUTO_INCREMENT,
  `calibration_id` int NOT NULL COMMENT '外键',
  `filepath` varchar(255) CHARACTER SET utf8mb3 COLLATE utf8mb3_general_ci NOT NULL,
  `serial_number` int NULL DEFAULT NULL,
  `timestamp` timestamp NULL DEFAULT CURRENT_TIMESTAMP ON UPDATE CURRENT_TIMESTAMP,
  PRIMARY KEY (`temperature_id`) USING BTREE,
  INDEX `calibration_id_fk1`(`calibration_id` ASC) USING BTREE,
  CONSTRAINT `calibration_id_fk1` FOREIGN KEY (`calibration_id`) REFERENCES `calibration_configurations` (`calibration_id`) ON DELETE RESTRICT ON UPDATE CASCADE
) ENGINE = InnoDB AUTO_INCREMENT = 586 CHARACTER SET = utf8mb3 COLLATE = utf8mb3_general_ci ROW_FORMAT = DYNAMIC;

SET FOREIGN_KEY_CHECKS = 1;
