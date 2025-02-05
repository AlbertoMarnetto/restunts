#ifndef RESTUNTS_SHAPE3D_H
#define RESTUNTS_SHAPE3D_H

#include "math.h"

int shape3d_load_all(void);
void shape3d_free_all(void);
void shape3d_init_shape(char far* shapeptr, struct SHAPE3D* gameshape);
unsigned transformed_shape_op(struct TRANSFORMEDSHAPE3D* arg_transshapeptr);
void set_projection(int i1, int i2, int i3, int i4);
int polarAngle(int z, int y);
unsigned select_cliprect_rotate(int angZ, int angX, int angY, struct RECTANGLE* cliprect, int unk);
void init_polyinfo(void);
void polyinfo_reset(void);
void get_a_poly_info(void);
void sub_204AE(struct VECTOR far* arg_verts, int arg_4, short* arg_6, short* arg_8, struct VECTOR* arg_vecarray, struct VECTOR* arg_vecptr);

#endif
