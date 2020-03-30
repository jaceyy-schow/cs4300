define move level1 F' R' D' R F' F'
define move level2 F U' R U
define move level3 R' D' R F' F'
define move level4 y F' R' D' R F' F' y'
define move level5 y F U' R U  y'
define move level6 y R' D' R F' F' y'
define move level7 y y F' R' D' R F' F' y' y'
define move level8 y y F U' R U y' y'
define move level9 y y R' D' R F' F' y' y'
define move level10 y' F' R' D' R F' F' y
define move level11 y' F U' R U y
define move level12 y' R' D' R F' F' y


define move red_edge2 D R F'
define move green_edge2 y' D R F' y
define move blue_edge2 y D R F' y'
define move orange_edge2 y' y' D R F' y y

define move bow_corner R' D R D'
define move ogw_corner R' D R D'
define move rbw_corner R' D R D'
define move orw_corner R' D R D' 
define move other_w R' D' R
define move other2_w F D F'
define move other3_w R' D2 R D R' D' R
define move other4_w L D L' R' D' R

define move g_right x' x' y' U R U' R' U' F' U F y x x
define move g_left x' x' y' U' L' U L U F U' F y x x
define move r_right x' x' y y U R U' R' U' F' U F y' y' x x
define move r_left x' x' y y U' L' U L U F U' F y' y' x x
define move b_right x' x' y U R U' R' U' F' U F y' x x 
define move b_left x' x' y U' L' U L U F U' F y' x x
define move o_left x' x' U' L' U L U F U' F x x
define move o_right x' x' U R U' R' U' F' U F x x

define move g_right_w x' x' y' U R U' R' U' F' U F U2 U R U' R' U' F' U F y x x
define move g_left_w x' x' y' U' L' U L U F U' F U R U' R' U' F' U F y x x
define move r_right_w x' x' y y U R U' R' U' F' U F U2 U R U' R' U' F' U F y' y' x x
define move r_left_w x' x' y y U' L' U L U F U' F y' y' U R U' R' U' F' U F x x
define move b_right_w x' x' y U R U' R' U' F' U F U2 U R U' R' U' F' U F y' x x 
define move b_left_w x' x' y U' L' U L U F U' F U R U' R' U' F' U F y' x x
define move o_left_w x' x' U' L' U L U F U' F U2 U R U' R' U' F' U F x x
define move o_right_w x' x' U R U' R' U' F' U F U2 U R U' R' U' F' U F   x x


define move yellow_cross y x' x' F R U R' U' F' x x y'
define move yellow_cross2 y y x' x' F R U R' U' F' x x y' y' 
define move fix_edges x' x' R U R' U R U2 R' U x x
define move fix_edges2 x' x' y' R U R' U R U2 R' U y x x
define move fix_edges3 x' x' y' y' R U R' U R U2 R' U y y x x
define move fix_edges4 x' x' y R U R' U R U2 R' U y' x x 


define move corner x' x'  U R U' L' U R' U' L x x
define move corner2 x' x' y U R U' L' U R' U' L y' x x
define move corner3 x' x' y y U R U' L' U R' U' L y' y' x x
define move corner4 x' x' y' U R U' L' U R' U' L y x x

define move test1 x' x' R' D' R D x x

define move spots F F B B U D' R R L L U D'