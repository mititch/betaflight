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


#include <stddef.h>
#include <stdlib.h>
#include <stdint.h>

#include "objects_tracking.h"

static uint8_t tracksSize = 0;
static objectTrack_t tracksFrame[MAX_SUPPORTED_TRACKING_OBJECTS_COUNT];


void setObjectsTracking(const objectTrack_t* frame, uint8_t size) {
    
    for (int i = 0; i < size; i++) {
        tracksFrame[i] = frame[i];
    }
    tracksSize = size;
}

uint8_t getTrackedObjectsSize(void) {
    return tracksSize;
}

objectTrack_t getTrackedObject(uint8_t index) {
    return tracksFrame[index];
}

void initObjectsTracking(bool fake){
 
    if (fake) {
        tracksFrame[0].x = 0;
        tracksFrame[0].y = 0;
        tracksFrame[0].locked = false;
        tracksFrame[1].x = 14;
        tracksFrame[1].y = 9;
        tracksFrame[1].locked = true;
        tracksFrame[2].x = 17;
        tracksFrame[2].y = 10;
        tracksFrame[2].locked = false;
        
        tracksSize = 3;
    }
}

