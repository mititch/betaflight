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

//#ifdef USE_OBJECTS_TRACKING

#include <stddef.h>
#include <stdlib.h>
#include <stdint.h>

#include "objects_tracking.h"


static objectTrack_t* _array = NULL;
static uint8_t _size = 0;


void _deepCopyObjectArray(objectTrack_t *source, objectTrack_t **destination, uint8_t size) {

    *destination = (objectTrack_t*)malloc(size * sizeof(objectTrack_t));
    
    for (size_t i = 0; i < size; i++) {
        (*destination)[i] = source[i];
    }
}

void setObjectsTracking(objectTrack_t* array, uint8_t size) {
    
    free(_array);
    _size = size;
    _array = array;
}

void getObjectsTracking(objectsTracking_t *tracking) {
    
    _deepCopyObjectArray(_array, &(tracking->tracks), _size);
    tracking->size = _size;
}

void getFakeObjectsTracking(objectsTracking_t *tracking) {
 
    uint8_t size = 3;

    objectTrack_t* array = (objectTrack_t*)malloc(size * sizeof(objectTrack_t));
    array[0].x = 0;
    array[0].y = 0;
    array[0].locked = false;
    array[1].x = 14;
    array[1].y = 9;
    array[1].locked = true;
    array[2].x = 17;
    array[2].y = 10;
    array[2].locked = false;
    
    tracking->tracks = array;
    tracking->size = size;
}

//#endif
