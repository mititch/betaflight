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


//#ifdef USE_OBJECTS_TRACKING

#include <stdint.h>
#include <stdbool.h>


typedef struct objectTrack_s {
    uint8_t x; //30
    uint8_t y; //16
    bool locked;
} objectTrack_t;

typedef struct objectsTracking_s {
    objectTrack_t* tracks;
    uint8_t size;
} objectsTracking_t;

void setObjectsTracking(objectTrack_t* array, uint8_t size);

void getObjectsTracking(objectsTracking_t *tracking);

void getFakeObjectsTracking(objectsTracking_t *tracking);
//#endif



