/* GIMP RGBA C-Source image dump (lives.c) */

static const struct {
  unsigned int 	 width;
  unsigned int 	 height;
  unsigned int 	 bytes_per_pixel; /* 2:RGB16, 3:RGB, 4:RGBA */ 
  unsigned char	 pixel_data[64 * 30 * 4 + 1];
} lives = {
  64, 30, 4,
  "\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000"
  "\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000"
  "\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000"
  "\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377"
  "\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000"
  "\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000"
  "\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000"
  "\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377"
  "\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\376\000\000\000\377\000"
  "\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000"
  "\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000"
  "\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377"
  "\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000"
  "\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000"
  "\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000"
  "\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377"
  "\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000"
  "\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\376\000\000\000\377\000\000\000\377\000\000"
  "\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000"
  "\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377"
  "\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000"
  "\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000"
  "\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000"
  "\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377"
  "\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000"
  "\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000"
  "\000\377\000\000\000\377\000\000\000\377\000\000\000\376\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000"
  "\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377"
  "\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000"
  "\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000"
  "\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000"
  "\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377"
  "\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000"
  "\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000"
  "\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000"
  "\377\000\000\000\377\000\000\000\376\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377"
  "\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000"
  "\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000"
  "\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000"
  "\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377"
  "\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000"
  "\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000"
  "\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000"
  "\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377"
  "\000\000\000\376\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000"
  "\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000"
  "\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000"
  "\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377"
  "\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000"
  "\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000"
  "\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000"
  "\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377"
  "\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\376\000"
  "\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000"
  "\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000"
  "\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377"
  "\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000"
  "\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000"
  "\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000"
  "\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377"
  "\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000"
  "\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\376\000\000\000\377\000\000"
  "\000\377\000\000\000\377\242\242\242\377\354\354\354\377}}}\377\000\000\000\377\000\000\000\377"
  "\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000"
  "\000\000\377\000\000\000\377\216\216\216\377\200\200\200\377\000\000\000\377\000\000\000\377\000"
  "\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000"
  "\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000"
  "\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377"
  "\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000"
  "\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000"
  "\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\376\000\000\000"
  "\377\000\000\000\377\000\000\000\377\333\333\333\377\377\377\377\377\265\265\265\377"
  "\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000"
  "\000\000\377\000\000\000\377\000\000\000\377\207\207\207\377\377\377\377\377\375\375\375"
  "\377___\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000"
  "\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000"
  "\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000"
  "\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377"
  "\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000"
  "\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000"
  "\000\377\000\000\000\376\000\000\000\377\000\000\000\377\000\000\000\377\335\335\335\377\377\377\377"
  "\377\265\265\265\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000"
  "\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377rrr\377\373\373\373\377\366"
  "\366\366\377MMM\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000"
  "\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000"
  "\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377"
  "\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000"
  "\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000"
  "\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000"
  "\377\000\000\000\377\000\000\000\376\000\000\000\377\000\000\000\377\000\000\000\377\336\336\336\377\377"
  "\377\377\377\263\263\263\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000"
  "\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377OOO\377"
  "CCC\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000"
  "\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377"
  "\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000"
  "\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000"
  "\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000"
  "\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377"
  "\000\000\000\377\000\000\000\376\000\000\000\377\000\000\000\377\000\000\000\377\336\336\336\377\377\377"
  "\377\377\261\261\261\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377"
  "\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000"
  "\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000"
  "\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000"
  "\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377"
  "\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000"
  "\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\026\026\026\377\210\210\210\377\215\215"
  "\215\377\004\004\004\377\000\000\000\377\000\000\000\377\000\000\000\377KKK\377\034\034\034\377\000\000"
  "\000\377\000\000\000\377\000\000\000\377\000\000\000\376\000\000\000\377\000\000\000\377\000\000\000\377\336\336"
  "\336\377\377\377\377\377\257\257\257\377\000\000\000\377\000\000\000\377\000\000\000\377\000"
  "\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000"
  "\000\377(((\377\000\000\000\377\000\000\000\377\000\000\000\377KKK\377\252\252\252\377DDD\377"
  "\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377JJJ\377\230\230\230\377"
  "&&&\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\061\061\061\377~~~\377\222\222"
  "\222\377xxx\377\062\062\062\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000"
  "\000\377\000\000\000\377\000\000\000\377!!!\377\214\214\214\377\305\305\305\377\360\360"
  "\360\377\377\377\377\377\377\377\377\377xxx\377\000\000\000\377\000\000\000\377\210\210"
  "\210\377\374\374\374\377\324\324\324\377\000\000\000\377\000\000\000\377\000\000\000\377\000"
  "\000\000\376\000\000\000\377\000\000\000\377\000\000\000\377\337\337\337\377\377\377\377\377\254"
  "\254\254\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377"
  "\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\230\230\230\377\375\375\375\377"
  "\261\261\261\377\000\000\000\377\000\000\000\377\304\304\304\377\377\377\377\377\304"
  "\304\304\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\321\321\321"
  "\377\377\377\377\377\253\253\253\377\000\000\000\377\000\000\000\377\005\005\005\377\256\256"
  "\256\377\366\366\366\377\377\377\377\377\377\377\377\377\377\377\377\377"
  "\370\370\370\377\274\274\274\377\031\031\031\377\000\000\000\377\000\000\000\377\000\000\000\377"
  "\026\026\026\377\255\255\255\377\361\361\361\377\377\377\377\377\377\377\377"
  "\377\377\377\377\377\377\377\377\377\377\377\377\377\237\237\237\377\000\000"
  "\000\377\000\000\000\377\232\232\232\377\377\377\377\377\365\365\365\377\004\004\004\377"
  "\000\000\000\377\000\000\000\377\000\000\000\376\000\000\000\377\000\000\000\377\000\000\000\377\341\341\341"
  "\377\377\377\377\377\253\253\253\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000"
  "\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\272\272"
  "\272\377\377\377\377\377\322\322\322\377\000\000\000\377\000\000\000\377\245\245\245"
  "\377\377\377\377\377\363\363\363\377###\377\000\000\000\377\000\000\000\377\000\000\000\377"
  "LLL\377\373\373\373\377\377\377\377\377\214\214\214\377\000\000\000\377\000\000\000\377"
  "\272\272\272\377\377\377\377\377\377\377\377\377\350\350\350\377\331\331"
  "\331\377\355\355\355\377\377\377\377\377\377\377\377\377\255\255\255\377"
  "\000\000\000\377\000\000\000\377\001\001\001\377\310\310\310\377\377\377\377\377\377\377\377"
  "\377\373\373\373\377\331\331\331\377\251\251\251\377\325\325\325\377\377"
  "\377\377\377\274\274\274\377\000\000\000\377\000\000\000\377YYY\377\354\354\354\377\320"
  "\320\320\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\376\000\000\000\377\000\000\000\377"
  "\000\000\000\377\344\344\344\377\377\377\377\377\250\250\250\377\000\000\000\377\000\000"
  "\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000"
  "\377\000\000\000\377\302\302\302\377\377\377\377\377\311\311\311\377\000\000\000\377"
  "\000\000\000\377===\377\370\370\370\377\377\377\377\377\215\215\215\377\000\000\000\377"
  "\000\000\000\377\000\000\000\377\252\252\252\377\377\377\377\377\361\361\361\377!!!\377"
  "\000\000\000\377{{{\377\376\376\376\377\374\374\374\377\230\230\230\377\004\004\004\377"
  "\000\000\000\377\006\006\006\377\241\241\241\377\377\377\377\377\333\333\333\377\000\000"
  "\000\377\000\000\000\377VVV\377\376\376\376\377\377\377\377\377\324\324\324\377R"
  "RR\377\000\000\000\377\000\000\000\377\206\206\206\377\342\342\342\377~~~\377\000\000\000\377"
  "\000\000\000\377\000\000\000\377\007\007\007\377\002\002\002\377\000\000\000\377\000\000\000\377\000\000\000\377\000"
  "\000\000\376\000\000\000\377\000\000\000\377\000\000\000\377\352\352\352\377\377\377\377\377\233"
  "\233\233\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377"
  "\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\316\316\316\377\377\377\377\377"
  "\277\277\277\377\000\000\000\377\000\000\000\377\000\000\000\377\315\315\315\377\377\377\377"
  "\377\320\320\320\377\000\000\000\377\000\000\000\377\003\003\003\377\342\342\342\377\377\377"
  "\377\377\271\271\271\377\000\000\000\377\000\000\000\377\323\323\323\377\377\377\377"
  "\377\273\273\273\377\000\000\000\377\000\000\000\377\031\031\031\377\243\243\243\377\364"
  "\364\364\377\377\377\377\377\303\303\303\377\000\000\000\377\000\000\000\377~~~\377\377"
  "\377\377\377\372\372\372\377QQQ\377\006\006\006\377\000\000\000\377\000\000\000\377\000\000\000\377"
  "\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000"
  "\000\000\377\000\000\000\377\000\000\000\377\000\000\000\376\000\000\000\377\000\000\000\377\000\000\000\377\362"
  "\362\362\377\377\377\377\377\217\217\217\377\000\000\000\377\000\000\000\377\000\000\000\377"
  "\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\324"
  "\324\324\377\377\377\377\377\271\271\271\377\000\000\000\377\000\000\000\377\000\000\000\377"
  "\202\202\202\377\377\377\377\377\371\371\371\377\071\071\071\377\000\000\000\377k"
  "kk\377\377\377\377\377\375\375\375\377[[[\377\000\000\000\377&&&\377\370\370\370"
  "\377\374\374\374\377LLL\377\033\033\033\377\235\235\235\377\352\352\352\377"
  "\377\377\377\377\377\377\377\377\327\327\327\377;;;\377\000\000\000\377\000\000\000\377"
  "WWW\377\375\375\375\377\377\377\377\377\376\376\376\377\353\353\353\377\307"
  "\307\307\377}}}\377\004\004\004\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000"
  "\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\376\000\000\000"
  "\377\000\000\000\377\011\011\011\377\364\364\364\377\377\377\377\377\207\207\207\377"
  "\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000"
  "\000\000\377\000\000\000\377\000\000\000\377\333\333\333\377\377\377\377\377\255\255\255"
  "\377\000\000\000\377\000\000\000\377\000\000\000\377\021\021\021\377\354\354\354\377\377\377\377"
  "\377\240\240\240\377\000\000\000\377\300\300\300\377\377\377\377\377\325\325\325"
  "\377\000\000\000\377\000\000\000\377bbb\377\377\377\377\377\343\343\343\377\241\241\241"
  "\377\353\353\353\377\377\377\377\377\377\377\377\377\352\352\352\377\226"
  "\226\226\377\006\006\006\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\247\247\247"
  "\377\366\366\366\377\377\377\377\377\377\377\377\377\377\377\377\377\377"
  "\377\377\377\322\322\322\377\065\065\065\377\000\000\000\377\000\000\000\377\000\000\000\377\000"
  "\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\376\000\000"
  "\000\377\000\000\000\377%%%\377\370\370\370\377\377\377\377\377|||\377\000\000\000\377"
  "\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000"
  "\000\000\377\000\000\000\377\336\336\336\377\377\377\377\377\251\251\251\377\000\000\000"
  "\377\000\000\000\377\000\000\000\377\000\000\000\377\264\264\264\377\377\377\377\377\333\333"
  "\333\377---\377\364\364\364\377\377\377\377\377\207\207\207\377\000\000\000\377"
  "\000\000\000\377{{{\377\377\377\377\377\376\376\376\377\377\377\377\377\377\377"
  "\377\377\347\347\347\377\231\231\231\377\033\033\033\377\000\000\000\377\000\000\000\377"
  "\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377///\377\206\206\206\377"
  "\266\266\266\377\342\342\342\377\377\377\377\377\377\377\377\377\314\314"
  "\314\377\001\001\001\377\000\000\000\377\000\000\000\377\000\000\000\377jjj\377SSS\377\000\000\000\377"
  "\000\000\000\377\000\000\000\377\000\000\000\376\000\000\000\377\000\000\000\377<<<\377\377\377\377\377"
  "\377\377\377\377YYY\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377"
  "\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\333\333\333\377\377\377"
  "\377\377\255\255\255\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\\\\\\\377"
  "\375\375\375\377\374\374\374\377\262\262\262\377\377\377\377\377\350\350"
  "\350\377\007\007\007\377\000\000\000\377\000\000\000\377nnn\377\377\377\377\377\377\377\377"
  "\377\344\344\344\377\223\223\223\377\020\020\020\377\000\000\000\377\000\000\000\377\000\000"
  "\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000"
  "\377\000\000\000\377\000\000\000\377\001\001\001\377\254\254\254\377\377\377\377\377\375\375"
  "\375\377III\377\000\000\000\377\000\000\000\377kkk\377\375\375\375\377\356\356\356\377"
  "\033\033\033\377\000\000\000\377\000\000\000\377\000\000\000\376\000\000\000\377\000\000\000\377LLL\377\377"
  "\377\377\377\375\375\375\377AAA\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377"
  "\000\000\000\377\030\030\030\377ppp\377\066\066\066\377\000\000\000\377\000\000\000\377\326\326\326"
  "\377\377\377\377\377\266\266\266\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000"
  "\377\000\000\000\377\335\335\335\377\377\377\377\377\375\375\375\377\377\377\377"
  "\377\247\247\247\377\000\000\000\377\000\000\000\377\000\000\000\377\063\063\063\377\370\370\370"
  "\377\373\373\373\377qqq\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000"
  "\377\026\026\026\377\314\314\314\377\300\300\300\377\000\000\000\377>>>\377...\377"
  "\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\036\036\036\377\373\373\373\377\377"
  "\377\377\377yyy\377\000\000\000\377\000\000\000\377ppp\377\377\377\377\377\377\377\377"
  "\377RRR\377\000\000\000\377\000\000\000\377\000\000\000\376\000\000\000\377\000\000\000\377lll\377\377"
  "\377\377\377\370\370\370\377!!!\377\000\000\000\377\031\031\031\377ddd\377\236\236"
  "\236\377\314\314\314\377\361\361\361\377\377\377\377\377\325\325\325\377"
  "\000\000\000\377\000\000\000\377\322\322\322\377\377\377\377\377\273\273\273\377\000\000"
  "\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\236\236\236\377\377\377\377"
  "\377\377\377\377\377\366\366\366\377\067\067\067\377\000\000\000\377\000\000\000\377\000\000"
  "\000\377\000\000\000\377\302\302\302\377\377\377\377\377\366\366\366\377\252\252"
  "\252\377PPP\377\032\032\032\377HHH\377\224\224\224\377\336\336\336\377\377\377"
  "\377\377\347\347\347\377HHH\377\365\365\365\377\353\353\353\377\230\230\230"
  "\377WWW\377???\377eee\377\274\274\274\377\377\377\377\377\376\376\376\377"
  "\\\\\\\377\000\000\000\377\000\000\000\377\071\071\071\377\370\370\370\377\371\371\371\377"
  "CCC\377\000\000\000\377\000\000\000\377\000\000\000\376\000\000\000\377\000\000\000\377\177\177\177\377"
  "\377\377\377\377\375\375\375\377\342\342\342\377\350\350\350\377\370\370"
  "\370\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377"
  "\377\377\377\377\310\310\310\377\000\000\000\377\000\000\000\377\316\316\316\377\377"
  "\377\377\377\270\270\270\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000"
  "\000\377\071\071\071\377\370\370\370\377\377\377\377\377\300\300\300\377\000\000\000"
  "\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\064\064\064\377\334\334\334\377"
  "\377\377\377\377\377\377\377\377\375\375\375\377\370\370\370\377\375\375"
  "\375\377\377\377\377\377\377\377\377\377\362\362\362\377~~~\377HHH\377\370"
  "\370\370\377\377\377\377\377\377\377\377\377\377\377\377\377\374\374\374"
  "\377\377\377\377\377\377\377\377\377\377\377\377\377\321\321\321\377\003\003"
  "\003\377\000\000\000\377\000\000\000\377\000\000\000\377YYY\377[[[\377\000\000\000\377\000\000\000\377\000"
  "\000\000\377\000\000\000\376\000\000\000\377\000\000\000\377FFF\377\371\371\371\377\377\377\377"
  "\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\373"
  "\373\373\377\350\350\350\377\307\307\307\377\214\214\214\377\024\024\024\377"
  "\000\000\000\377\000\000\000\377jjj\377\273\273\273\377QQQ\377\000\000\000\377\000\000\000\377\000"
  "\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\263\263\263\377\362\362\362\377xx"
  "x\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\034\034\034"
  "\377\245\245\245\377\342\342\342\377\367\367\367\377\376\376\376\377\367"
  "\367\367\377\342\342\342\377\256\256\256\377<<<\377\000\000\000\377\000\000\000\377r"
  "rr\377\326\326\326\377\371\371\371\377\377\377\377\377\377\377\377\377\377"
  "\377\377\377\362\362\362\377\273\273\273\377***\377\000\000\000\377\000\000\000\377\000"
  "\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000"
  "\000\376\000\000\000\377\000\000\000\377\000\000\000\377xxx\377\272\272\272\377\300\300\300\377"
  "\261\261\261\377\236\236\236\377www\377\067\067\067\377\000\000\000\377\000\000\000\377"
  "\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000"
  "\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\012\012"
  "\012\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000"
  "\377\000\000\000\377\000\000\000\377\000\000\000\377!!!\377:::\377###\377\000\000\000\377\000\000\000\377"
  "\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377...\377eee\377{{{\377X"
  "XX\377\034\034\034\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000"
  "\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\376\000\000\000"
  "\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377"
  "\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000"
  "\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000"
  "\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000"
  "\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377"
  "\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000"
  "\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000"
  "\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000"
  "\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\376\000\000\000\377\000\000\000\377"
  "\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000"
  "\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000"
  "\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000"
  "\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377"
  "\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000"
  "\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000"
  "\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000"
  "\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377"
  "\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\376\000\000\000\377\000\000\000\377\000\000\000\377\000"
  "\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000"
  "\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000"
  "\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377"
  "\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000"
  "\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000"
  "\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000"
  "\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377"
  "\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000"
  "\000\000\377\000\000\000\377\000\000\000\376\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000"
  "\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000"
  "\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377"
  "\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000"
  "\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000"
  "\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000"
  "\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377"
  "\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000"
  "\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000"
  "\000\377\000\000\000\376",
};

