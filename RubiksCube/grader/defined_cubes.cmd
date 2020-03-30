define cube wr_edge ****w**w* ****g**** *r**r**** ****b**** ****o**** ****y****
define cube wg_edge ***ww**** *g**g**** ****r**** ****b**** ****o**** ****y****
define cube wb_edge ****ww*** ****g**** ****r**** *b**b**** ****o**** ****y****
define cube wo_edge *w**w**** ****g**** ****r**** ****b**** *o**o**** ****y****

define cube wr_wg_edge ***ww**w* *g**g**** *r**r**** ****b**** ****o**** ****y****
define cube wr_wb_edge ***ww**w* ****g**** *r**r**** *b**b**** ****o**** ****y****
define cube wg_wb_edge ***www*** *g**g**** ****r**** *b**b**** ****o**** ****y****
define cube wg_wo_edge *w*ww**** *g**g**** ****r**** ****b**** *o**o**** ****y****
define cube wo_wb_edge *w**ww*** ****g**** ****r**** *b**b**** *o**o**** ****y****
define cube wo_wr_edge *w**w**w* ****g**** *r**r**** ****b**** *o**o**** ****y****

define cube wo_wr_wb *w**ww*w* ****g**** *r**r**** *b**b**** *o**o**** ****y****
define cube wo_wr_wg *w*ww**w* *g**g**** *r**r**** ****b**** *o**o**** ****y****
define cube wb_wg_wr ***www*w* *g**g**** *r**r**** *b**b**** ****o**** ****y****
define cube wb_wg_wo *w*www*** *g**g**** ****r**** *b**b**** *o**o**** ****y****

define cube white_cross *w*www*w* *g**g**** *r**r**** *b**b**** *o**o**** *********

define cube wog_corner_0 ww*www*w* gg**g**** *r**r**** *b**b**** *oo*o**** *********
define cube wob_corner_0 *wwwww*w* *g**g**** *r**r**** *bb*b**** oo**o**** *********
define cube wrg_corner_0 *w*wwwww* *gg*g**** rr**r**** *b**b**** *o**o**** *********
define cube wrb_corner_0 *w*www*ww *g**g**** *rr*r**** bb**b**** *o**o**** *********

define cube ow_corners wwwwww*w* gg**g**** *r**r**** *bb*b**** ooo*o**** *********
define cube bw_corners *wwwww*ww *g**g**** *rr*r**** bbb*b**** oo**o**** *********
define cube rw_corners *w*wwwwww *gg*g**** rrr*r**** bb*b***** *o**o**** *********
define cube gw_corners ww*wwwww* ggg*g**** rr**r**** *b**b**** *oo*o**** *********
define cube og_rb_corner ww*www*ww gg**g**** *rr*r**** bb**b**** *oo*o**** *********
define cube rg_ob_corner *wwwwww** *gg*g**** rr**r**** *bb*b**** oo**o**** *********

define cube rg_rb_ob_corners *wwwwwwww *gg*g**** rrr*r**** bbb*b**** oo**o**** *********
define cube rb_bo_og_corners wwwwww*ww gg**g**** *rr*r**** bbb*b**** ooo*o**** *********
define cube og_rg_rb_corners ww*wwwwww ggg*g**** rrr*r**** bb**b**** *oo*o**** *********


define cube layer1 wwwwwwwww ggg*g**** rrr*r**** bbb*b**** ooo*o**** *********

define cube ob_t wwwwwwwww ggg*g**** rrr*r**** bbb*b**** ooo*o**o* ****y**b*
define cube og_t wwwwwwwww ggg*g**** rrr*r**** bbb*b**** ooo*o**o* ****y**g*
define cube go_t wwwwwwwww ggg*g**g* rrr*r**** bbb*b**** ooo*o**** ***oy****
define cube gr_t wwwwwwwww ggg*g**g* rrr*r**** bbb*b**** ooo*o**** ***ry****
define cube bo_t wwwwwwwww ggg*g**** rrr*r**** bbb*b**b* ooo*o**** ****yo***
define cube br_t wwwwwwwww ggg*g**** rrr*r**** bbb*b**b* ooo*o**** ****yr***
define cube rg_t wwwwwwwww ggg*g**** rrr*r**r* bbb*b**** ooo*o**** *g**y****
define cube rb_t wwwwwwwww ggg*g**** rrr*r**r* bbb*b**** ooo*o**** *b**y****

define cube rg_edge wwwwwwwww ggg*gg*** rrrrr**** bbb*b**** ooo*o**** *********
define cube rb_edge wwwwwwwww ggg*g**** rrr*rr*** bbbbb**** ooo*o**** *********
define cube bo_edge wwwwwwwww ggg*g**** rrr*r**** bbb*bb*** ooooo**** *********
define cube og_edge wwwwwwwww ggggg**** rrr*r**** bbb*b**** ooo*oo*** *********

define cube ft1 rb_t rg_edge
define cube ft2 rb_t og_edge
define cube ft3 rg_t rb_edge
define cube ft4 rg_t og_edge
define cube ft5 og_t bo_edge
define cube ft6 og_t rg_edge
define cube ft7 ob_t rb_edge
define cube ft8 ob_t rg_edge
define cube ft9 go_t rg_edge
define cube ft10 go_t bo_edge
define cube ft11 gr_t rb_edge
define cube ft12 gr_t og_edge
define cube ft13 br_t rg_edge
define cube ft14 br_t og_edge
define cube ft15 bo_t rb_edge
define cube ft16 bo_t og_edge

define cube et1 rb_t rg_edge og_edge
define cube et2 rb_t rg_edge bo_edge
define cube et11 rb_t bo_edge og_edge
define cube et3 rg_t rb_edge og_edge
define cube et4 rg_t rb_edge bo_edge
define cube et13 rg_t og_edge bo_edge
define cube et5 og_t bo_edge rb_edge
define cube et6 og_t bo_edge rg_edge
define cube et12 og_t rb_edge rg_edge
define cube et7 ob_t og_edge rg_edge
define cube et8 ob_t rb_edge og_edge
define cube et14 ob_t rb_edge rg_edge
define cube et9 go_t rb_edge bo_edge
define cube et10 go_t bo_edge rg_edge
define cube et15 go_t rb_edge bo_edge
define cube et16 gr_t rb_edge bo_edge
define cube et17 gr_t bo_edge og_edge
define cube et18 gr_t rb_edge og_edge

define cube rg_rb_edge wwwwwwwww ggg*gg*** rrrrrr*** bbbbb**** ooo*o**** *********
define cube rb_bo_edge wwwwwwwww ggg*g**** rrr*rr*** bbbbbb*** ooooo**** *********
define cube bo_og_edge wwwwwwwww ggggg**** rrr*r**** bbb*bb*** oooooo*** *********
define cube rg_og_edge wwwwwwwww gggggg*** rrrrr**** bbb*b**** ooo*oo*** *********
define cube rg_bo_edge wwwwwwwww ggg*gg*** rrrrr**** bbb*bb*** ooooo**** *********
define cube rb_og_edge wwwwwwwww ggggg**** rrr*rr*** bbbbb**** ooo*oo*** *********

define cube rg_rb_bo_edge wwwwwwwww ggg*gg*** rrrrrr*** bbbbbb*** ooooo**** *********
define cube rb_bo_og_edge wwwwwwwww ggggg**** rrr*rr*** bbbbbb*** oooooo*** *********
define cube bo_og_rg_edge wwwwwwwww gggggg*** rrrr***** bbb*bb*** oooooo*** *********
define cube og_rg_rb_edge wwwwwwwww gggggg*** rrrrrr*** bbbbb**** ooo*oo*** *********

define cube layer2 wwwwwwwww gggggg*** rrrrrr*** bbbbbb*** oooooo*** *********

define cube yellow_l1 wwwwwwwww gggggg*** rrrrrr*** bbbbbb*** oooooo*** *y*yy****
define cube yellow_l2 wwwwwwwww gggggg*** rrrrrr*** bbbbbb*** oooooo*** *y**yy***
define cube yellow_l3 wwwwwwwww gggggg*** rrrrrr*** bbbbbb*** oooooo*** ***yy**y*
define cube yellow_l4 wwwwwwwww gggggg*** rrrrrr*** bbbbbb*** oooooo*** ****yy*y*

define cube yellow_line1 wwwwwwwww gggggg*** rrrrrr*** bbbbbb*** oooooo*** *y**y**y*
define cube yellow_line2 wwwwwwwww gggggg*** rrrrrr*** bbbbbb*** oooooo*** ***yyy***

define cube yellow_cross wwwwwwwww gggggg*** rrrrrr*** bbbbbb*** oooooo*** *y*yyy*y*
define cube by_edge wwwwwwwww gggggg*** rrrrrr*** bbbbbb*b* oooooo*** *y*yyy*y*
define cube ry_edge wwwwwwwww gggggg*** rrrrrr*r* bbbbbb*b* oooooo*** *y*yyy*y*
define cube gy_edge wwwwwwwww gggggg*g* rrrrrr*r* bbbbbb*b* oooooo*** *y*yyy*y*
define cube cross&edges wwwwwwwww gggggg*g* rrrrrr*r* bbbbbb*b* oooooo*o* *y*yyy*y*

define cube yob_corner wwwwwwwww gggggg*g* rrrrrr*r* bbbbbb*bb oooooooo* *y*yyy*yy
define cube yog_corner wwwwwwwww gggggggg* rrrrrr*r* bbbbbb*b* oooooo*oo *y*yyyyy*
define cube yrg_corner wwwwwwwww gggggg*gg rrrrrrrr* bbbbbb*b* oooooo*o* yy*yyy*y*
define cube yrb_corner wwwwwwwww gggggg*g* rrrrrr*rr bbbbbbbb* oooooo*o* *yyyyy*y*

define cube yob_yog_corner yob_corner yog_corner
define cube yog_yrg_corner yog_corner yrg_corner
define cube yrg_yrb_corner yrg_corner yrb_corner
define cube yob_yrg_corner yob_corner yrg_corner
define cube yob_yrb_corner yob_corner yrb_corner
define cube yog_yrb_corner yog_corner yrb_corner 

define cube yob_yog_yrg_corner yob_corner yog_corner yrg_corner
define cube yob_yog_yrb_corner yob_corner yog_corner yrb_corner
define cube yob_yrg_yrb_corner yob_corner yrg_corner yrb_corner

define cube yog_yrg_yrb_corner  yog_corner yrg_corner yrb_corner

define cube yrg_01 wwwwwwwww ****g***r ****r*y** ****b**** ****o**** g***y****
define cube yrg_02 wwwwwwwww ****g***g ****r*r** ****b**** ****o**** y***y****
define cube yrg_03 wwwwwwwww ****g***y ****r*g** ****b**** ****o**** r***y****

define cube yob_01 wwwwwwwww ****g**** ****r**** ****b***b ****o*o** ****y***y
define cube yob_02 wwwwwwwww ****g**** ****r**** ****b***y ****o*b** ****y***o
define cube yob_03 wwwwwwwww ****g**** ****r**** ****b***o ****o*y** ****y***b

define cube yrb_01 ****w**** ****g**** ****r***r ****b*b** ****o**** **y*y****
define cube yrb_02 ****w**** ****g**** ****r***b ****b*y** ****o**** **r*y****
define cube yrb_03 ****w**** ****g**** ****r***y ****b*r** ****o**** **b*y****

define cube ygo_01 ****w**** ****g*y** ****r**** ****b**** ****o***g ****y*o**
define cube ygo_02 ****w**** ****g*o** ****r**** ****b**** ****o***y ****y*g**
define cube ygo_03 ****w**** ****g*g** ****r**** ****b**** ****o***o ****y*y**

define cube stuff00 cross&edges yrg_01 yob_01 yrb_01 ygo_01
define cube stuff01 cross&edges yrg_01 yob_02 yrb_02 ygo_02
define cube stuff02 cross&edges yrg_01 yob_02 yrb_03 ygo_03
define cube stuff03 cross&edges yrg_01 yob_03 yrb_03 ygo_03

define cube stuff10 cross&edges yrg_02 yob_02 yrb_02 ygo_02
define cube stuff11 cross&edges yrg_02 yob_03 yrb_03 ygo_03
define cube stuff12 cross&edges yrg_02 yob_03 yrb_01 ygo_01
define cube stuff13 cross&edges yrg_02 yob_01 yrb_01 ygo_01

define cube stuff20 cross&edges yrg_03 yob_03 yrb_03 ygo_03
define cube stuff21 cross&edges yrg_03 yob_01 yrb_01 ygo_01
define cube stuff22 cross&edges yrg_03 yob_01 yrb_02 ygo_02
define cube stuff23 cross&edges yrg_03 yob_03 yrb_03 ygo_03

define cube ol_01 wwwwwwwww ****g*ygy ********* ****b*yby ********* *********
define cube ol_11 wwwwwwwww ****g**** ****r*yry ****b**** ****o*yoy *********
define cube ol_21 wwwwwwwww ****g**** ****r*y** ****b*y*y ****o***y *y*yyy*y*
define cube ol_31 wwwwwwwww ****g*y** ****r*y*y ****b***y ****o**** *y*yyy*y*
define cube ol_41 wwwwwwwww ****g*y*y ****r***y ****b**** ****o*y** *y*yyy*y*
define cube ol_51 wwwwwwwww ****g***y ****r**** ****b*y** ****o*y*y *y*yyy*y*

define cube yellow ********* ********* ********* ********* ********* yyyyyyyyy

define cube ol_02 ol_01 ygo_01 yrg_03 yob_02 yrb_02
define cube ol_12 ol_11 yrb_03 yrg_01 yob_03 ygo_02
define cube ol_22 ol_21 yob_02 yrb_02 ygo_02 yrg_01
define cube ol_32 ol_31 ygo_01 yrg_01 yrb_03 yob_02
define cube ol_42 ol_41 ygo_01 yrg_03 yrb_03 yob_03
define cube ol_52 ol_51 yrg_03 yrb_02 ygo_02 yob_03

define cube ol_finished layer2 yellow


define cube solved wwwwwwwww ggggggggg rrrrrrrrr bbbbbbbbb ooooooooo yyyyyyyyy
define cube dot wwwwwwwww bbbbgbbbb ooooroooo ggggbgggg rrrrorrrr yyyyyyyyy
