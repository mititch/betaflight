/*
 * This file is part of Cleanflight and Betaflight.
 *
 * Cleanflight and Betaflight are free software. You can redistribute
 * this software and/or modify this software under the terms of the
 * GNU General Public License as published by the Free Software
 * Foundation, either version 3 of the License, or (at your option)
 * any later version.
 *
 * Cleanflight and Betaflight are distributed in the hope that they
 * will be useful, but WITHOUT ANY WARRANTY; without even the implied
 * warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * See the GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this software.
 *
 * If not, see <http://www.gnu.org/licenses/>.
 */

#pragma once

#include <stdint.h>
#include <stdbool.h>

#define MAX_SUPPORTED_TRACKING_OBJECTS_COUNT 3

typedef struct objectTrack_s {
    uint8_t x; //30
    uint8_t y; //16
    bool locked;
} objectTrack_t;

void initObjectsTracking(bool fake);

void setObjectsTracking(const objectTrack_t* array, uint8_t size);

uint8_t getTrackedObjectsSize();

objectTrack_t getTrackedObject(uint8_t index);
