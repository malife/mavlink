/*******************************************************************************
 
 Copyright (C) 2011 Lorenz Meier lm ( a t ) inf.ethz.ch
 
 This program is free software: you can redistribute it and/or modify
 it under the terms of the GNU General Public License as published by
 the Free Software Foundation, either version 3 of the License, or
 (at your option) any later version.
 
 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.
 
 You should have received a copy of the GNU General Public License
 along with this program.  If not, see <http://www.gnu.org/licenses/>.
 
 ****************************************************************************/

/* This assumes you have the mavlink headers on your include path
 or in the same folder as this source file */

#ifndef MAVLINK_MISSIONLIB_DATA_H
#define MAVLINK_MISSIONLIB_DATA_H

// Disable auto-data structures
#ifndef MAVLINK_NO_DATA
#define MAVLINK_NO_DATA
#endif

#include "mavlink.h"
#include <stdbool.h>

/* MISSION LIB DATA STORAGE */

/// Parameter Enum listing the PMs to exchange with QGC
/* MISSION LIB DATA STORAGE */
enum MAVLINK_PM_PARAMETERS
{
	MAVLINK_PM_PARAM_SYSTEM_ID,
	MAVLINK_PM_PARAM_GDNC_TSTAR,
	MAVLINK_PM_PARAM_GDNC_TURN_LEAD,

	MAVLINK_PM_PARAM_CTRL_UHOLD_P,
	MAVLINK_PM_PARAM_CTRL_UHOLD_I,
	MAVLINK_PM_PARAM_CTRL_UHOLD_D,

	MAVLINK_PM_PARAM_CTRL_DE_FF,

	MAVLINK_PM_PARAM_CTRL_HE2TH_P,
	MAVLINK_PM_PARAM_CTRL_HE2TH_I,
	MAVLINK_PM_PARAM_CTRL_HE2TH_D,

	MAVLINK_PM_PARAM_CTRL_TH2DT_P,
	MAVLINK_PM_PARAM_CTRL_TH2DT_I,
	MAVLINK_PM_PARAM_CTRL_TH2DT_D,

	MAVLINK_PM_PARAM_CTRL_DT_FF,

	MAVLINK_PM_PARAM_CTRL_ROLL_P,
	MAVLINK_PM_PARAM_CTRL_ROLL_I,
	MAVLINK_PM_PARAM_CTRL_ROLL_D,

	MAVLINK_PM_PARAM_CTRL_YAW_P,
	MAVLINK_PM_PARAM_CTRL_YAW_I,
	MAVLINK_PM_PARAM_CTRL_YAW_D,

	MAVLINK_PM_PARAM_CMDS_U_C,
	MAVLINK_PM_PARAM_CMDS_H_C_MID,
	MAVLINK_PM_PARAM_CMDS_PSID_C_MID,
	MAVLINK_PM_PARAM_CMDS_RTB,
	MAVLINK_PM_PARAM_CMDS_FOLLOW,
	MAVLINK_PM_PARAM_CMDS_IS_MANUAL,
	MAVLINK_PM_PARAM_CMDS_GDNC_MODE,
	MAVLINK_PM_PARAM_CMDS_VIEW_IDX,

	MAVLINK_PM_MAX_PARAM_COUNT // VERY IMPORTANT! KEEP THIS AS LAST ENTRY
};

/// Parameter Data Structure
/* DO NOT EDIT THIS STRUCT! */
typedef struct _mavlink_pm_storage {
	char param_names[MAVLINK_PM_MAX_PARAM_COUNT][MAVLINK_MSG_PARAM_VALUE_FIELD_PARAM_ID_LEN];      ///< Parameter names
	float param_values[MAVLINK_PM_MAX_PARAM_COUNT];    ///< Parameter values
	uint16_t next_param;
	uint16_t size;
} mavlink_pm_storage;

void mavlink_pm_reset_params(mavlink_pm_storage* pm);

#endif