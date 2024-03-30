/* GIMP RGBA C-Source image dump (score.c) */

static const struct {
  unsigned int 	 width;
  unsigned int 	 height;
  unsigned int 	 bytes_per_pixel; /* 2:RGB16, 3:RGB, 4:RGBA */ 
  unsigned char	 pixel_data[64 * 26 * 4 + 1];
} score = {
  64, 26, 4,
  "\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000"
  "\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000"
  "\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000"
  "\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377"
  "\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000"
  "\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000"
  "\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000"
  "\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377"
  "\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\346\000\000\000\377\000"
  "\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000"
  "\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000"
  "\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377"
  "\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000"
  "\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000"
  "\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000"
  "\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377"
  "\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000"
  "\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\346\000\000\000\377\000\000\000\377\000\000"
  "\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000"
  "\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377"
  "\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000"
  "\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000"
  "\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000"
  "\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377"
  "\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000"
  "\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000"
  "\000\377\000\000\000\377\000\000\000\377\000\000\000\346\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000"
  "\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377"
  "\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000"
  "\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000"
  "\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000"
  "\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377"
  "\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000"
  "\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000"
  "\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000"
  "\377\000\000\000\377\000\000\000\346\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377"
  "\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000"
  "\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000"
  "\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000"
  "\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377"
  "\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000"
  "\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000"
  "\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000"
  "\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377"
  "\000\000\000\346\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000"
  "\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000"
  "\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000"
  "\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377"
  "\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000"
  "\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000"
  "\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000"
  "\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377"
  "\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\346\000"
  "\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000"
  "\000\377\012\012\012\377KKK\377>>>\377\003\003\003\377\000\000\000\377\000\000\000\377\000\000\000\377"
  "\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000"
  "\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000"
  "\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000"
  "\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377"
  "\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000"
  "\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000"
  "\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\346\000\000\000\377\000\000\000"
  "\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377^^^\377\311\311\311\377\365\365"
  "\365\377\377\377\377\377\377\377\377\377\362\362\362\377\314\314\314\377"
  "YYY\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000"
  "\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377"
  "\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000"
  "\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000"
  "\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000"
  "\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377"
  "\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\346\000"
  "\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\235\235\235\377\371\371"
  "\371\377\377\377\377\377\361\361\361\377\335\335\335\377\341\341\341\377"
  "\367\367\367\377\377\377\377\377\266\266\266\377\000\000\000\377\000\000\000\377\000\000"
  "\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000"
  "\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377"
  "\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000"
  "\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000"
  "\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000"
  "\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377"
  "\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\346\000\000\000\377\000\000\000\377\000\000\000\377\000"
  "\000\000\377\222\222\222\377\376\376\376\377\367\367\367\377\231\231\231\377"
  "\013\013\013\377\000\000\000\377\000\000\000\377\015\015\015\377RRR\377\021\021\021\377\000\000\000"
  "\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377"
  "\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000"
  "\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000"
  "\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000"
  "\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377"
  "\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000"
  "\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\346\000\000\000\377\000\000"
  "\000\377\000\000\000\377\001\001\001\377\350\350\350\377\377\377\377\377\233\233\233\377"
  "\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000"
  "\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\001\001\001\377PPP\377III\377"
  "\002\002\002\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000"
  "\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000"
  "\000\377\000\000\000\377\001\001\001\377\000\000\000\377\000\000\000\377\000\000\000\377\071\071\071\377ZZZ"
  "\377\001\001\001\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\002\002\002\377"
  "\006\006\006\377\001\001\001\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\221"
  "\221\221\377\320\320\320\377@@@\377\000\000\000\377\000\000\000\377\000\000\000\346\000\000\000\377"
  "\000\000\000\377\000\000\000\377\014\014\014\377\372\372\372\377\377\377\377\377rrr\377"
  "\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000"
  "\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377WWW\377\335\335\335\377\377\377\377"
  "\377\377\377\377\377\354\354\354\377\261\261\261\377\035\035\035\377\000\000\000\377"
  "\000\000\000\377\000\000\000\377TTT\377\301\301\301\377\344\344\344\377\350\350\350\377"
  "\305\305\305\377GGG\377\000\000\000\377\000\000\000\377\000\000\000\377\253\253\253\377\350"
  "\350\350\377...\377\220\220\220\377\343\343\343\377\376\376\376\377\377\377"
  "\377\377\271\271\271\377\000\000\000\377\000\000\000\377\000\000\000\377ZZZ\377\316\316\316"
  "\377\363\363\363\377\374\374\374\377\356\356\356\377\310\310\310\377PPP\377"
  "\000\000\000\377\000\000\000\377\000\000\000\377\322\322\322\377\377\377\377\377\227\227\227"
  "\377\000\000\000\377\000\000\000\377\000\000\000\346\000\000\000\377\000\000\000\377\000\000\000\377\001\001\001\377"
  "\336\336\336\377\377\377\377\377\355\355\355\377\270\270\270\377\225\225"
  "\225\377yyy\377ccc\377\012\012\012\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377"
  "\000\000\000\377;;;\377\352\352\352\377\377\377\377\377\347\347\347\377\336\336"
  "\336\377\370\370\370\377\377\377\377\377\252\252\252\377\000\000\000\377\000\000\000"
  "\377mmm\377\364\364\364\377\377\377\377\377\377\377\377\377\377\377\377\377"
  "\377\377\377\377\345\345\345\377%%%\377\000\000\000\377\000\000\000\377\310\310\310\377"
  "\377\377\377\377\327\327\327\377\377\377\377\377\374\374\374\377\343\343"
  "\343\377\375\375\375\377\356\356\356\377\000\000\000\377\000\000\000\377]]]\377\362\362"
  "\362\377\377\377\377\377\355\355\355\377\340\340\340\377\365\365\365\377"
  "\377\377\377\377\345\345\345\377\010\010\010\377\000\000\000\377\000\000\000\377\243\243"
  "\243\377\362\362\362\377www\377\000\000\000\377\000\000\000\377\000\000\000\346\000\000\000\377\000"
  "\000\000\377\000\000\000\377\000\000\000\377[[[\377\337\337\337\377\377\377\377\377\377\377"
  "\377\377\377\377\377\377\377\377\377\377\377\377\377\377\361\361\361\377"
  "\252\252\252\377\001\001\001\377\000\000\000\377\000\000\000\377\000\000\000\377\304\304\304\377"
  "\377\377\377\377\305\305\305\377\004\004\004\377\000\000\000\377NNN\377\304\304\304\377"
  "mmm\377\000\000\000\377\034\034\034\377\350\350\350\377\377\377\377\377\322\322\322"
  "\377uuu\377www\377\341\341\341\377\377\377\377\377\245\245\245\377\000\000\000"
  "\377\000\000\000\377\321\321\321\377\377\377\377\377\377\377\377\377\322\322\322"
  "\377UUU\377\000\000\000\377\363\363\363\377\364\364\364\377\003\003\003\377\000\000\000\377"
  "\332\332\332\377\377\377\377\377\256\256\256\377\006\006\006\377\000\000\000\377%%%\377"
  "\335\335\335\377\377\377\377\377@@@\377\000\000\000\377\000\000\000\377\000\000\000\377\002\002"
  "\002\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\346\000\000\000\377\000\000\000\377\000\000\000"
  "\377\000\000\000\377\000\000\000\377\001\001\001\377iii\377\227\227\227\377\252\252\252\377"
  "\303\303\303\377\354\354\354\377\377\377\377\377\377\377\377\377\265\265"
  "\265\377\000\000\000\377\000\000\000\377VVV\377\374\374\374\377\357\357\357\377---\377"
  "\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\226\226\226"
  "\377\377\377\377\377\345\345\345\377\033\033\033\377\000\000\000\377\000\000\000\377ppp"
  "\377\377\377\377\377\331\331\331\377\000\000\000\377\000\000\000\377\322\322\322\377"
  "\377\377\377\377\327\327\327\377\020\020\020\377\000\000\000\377\000\000\000\377\346\346"
  "\346\377\344\344\344\377\000\000\000\377iii\377\376\376\376\377\331\331\331\377"
  "\002\002\002\377\000\000\000\377ttt\377\333\333\333\377\377\377\377\377\351\351\351\377"
  "\020\020\020\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377"
  "\000\000\000\377\000\000\000\346\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000"
  "\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\017\017\017\377\260\260\260"
  "\377\377\377\377\377\373\373\373\377EEE\377\000\000\000\377\257\257\257\377\377"
  "\377\377\377\253\253\253\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000"
  "\000\377\000\000\000\377\000\000\000\377\307\307\307\377\377\377\377\377\245\245\245\377"
  "\000\000\000\377\000\000\000\377\000\000\000\377\020\020\020\377\371\371\371\377\353\353\353\377"
  "\000\000\000\377\000\000\000\377\322\322\322\377\377\377\377\377ttt\377\000\000\000\377\000\000"
  "\000\377\000\000\000\377KKK\377AAA\377\000\000\000\377\252\252\252\377\377\377\377\377"
  "\225\225\225\377xxx\377\326\326\326\377\376\376\376\377\377\377\377\377\325"
  "\325\325\377RRR\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000"
  "\000\377\000\000\000\377\000\000\000\377\000\000\000\346\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000"
  "\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377"
  "\001\001\001\377\344\344\344\377\377\377\377\377\205\205\205\377\000\000\000\377\322"
  "\322\322\377\377\377\377\377\\\\\\\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000"
  "\000\377\000\000\000\377\000\000\000\377\000\000\000\377\325\325\325\377\377\377\377\377{{{\377"
  "\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\366\366\366\377\357\357\357\377"
  "\000\000\000\377\000\000\000\377\322\322\322\377\377\377\377\377\\\\\\\377\000\000\000\377"
  "\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\302\302\302\377\377\377"
  "\377\377\340\340\340\377\377\377\377\377\377\377\377\377\332\332\332\377"
  "\200\200\200\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000"
  "\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\346\000\000\000\377\000\000\000\377"
  "\000\000\000\377%%%\377\001\001\001\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000"
  "\377\000\000\000\377\000\000\000\377\340\340\340\377\377\377\377\377~~~\377\000\000\000\377"
  "\332\332\332\377\375\375\375\377\066\066\066\377\000\000\000\377\000\000\000\377\000\000\000\377"
  "\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\322\322\322\377\377\377\377\377"
  "|||\377\000\000\000\377\000\000\000\377\000\000\000\377(((\377\373\373\373\377\343\343\343"
  "\377\000\000\000\377\000\000\000\377\322\322\322\377\377\377\377\377^^^\377\000\000\000\377"
  "\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\303\303\303\377\377\377"
  "\377\377\376\376\376\377\325\325\325\377yyy\377\000\000\000\377\000\000\000\377\000\000\000"
  "\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\223\223\223\377\352\352\352"
  "\377rrr\377\000\000\000\377\000\000\000\377\000\000\000\346\000\000\000\377\000\000\000\377mmm\377\373"
  "\373\373\377\302\302\302\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000"
  "\000\377\000\000\000\377\210\210\210\377\375\375\375\377\366\366\366\377\061\061\061"
  "\377\000\000\000\377\304\304\304\377\377\377\377\377\217\217\217\377\000\000\000\377"
  "\000\000\000\377\000\000\000\377\000\000\000\377\025\025\025\377\003\003\003\377\000\000\000\377\271\271\271"
  "\377\377\377\377\377\265\265\265\377\000\000\000\377\000\000\000\377\000\000\000\377\225\225"
  "\225\377\377\377\377\377\302\302\302\377\000\000\000\377\000\000\000\377\322\322\322"
  "\377\377\377\377\377```\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000"
  "\377\000\000\000\377\246\246\246\377\377\377\377\377\271\271\271\377\000\000\000\377"
  "\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377yyy\377\304\304\304\377\026\026\026"
  "\377\000\000\000\377\272\272\272\377\377\377\377\377\266\266\266\377\000\000\000\377"
  "\000\000\000\377\000\000\000\346\000\000\000\377\000\000\000\377ddd\377\376\376\376\377\377\377\377"
  "\377\273\273\273\377HHH\377\005\005\005\377\024\024\024\377ttt\377\303\303\303\377"
  "\374\374\374\377\377\377\377\377\241\241\241\377\000\000\000\377\000\000\000\377www\377"
  "\375\375\375\377\364\364\364\377\224\224\224\377$$$\377<<<\377\253\253\253"
  "\377\362\362\362\377\275\275\275\377\000\000\000\377ggg\377\374\374\374\377\372"
  "\372\372\377\243\243\243\377hhh\377\241\241\241\377\366\366\366\377\374\374"
  "\374\377kkk\377\000\000\000\377\000\000\000\377\322\322\322\377\377\377\377\377ccc\377"
  "\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377EEE\377\365\365"
  "\365\377\375\375\375\377\275\275\275\377jjj\377///\377ooo\377\262\262\262"
  "\377\366\366\366\377\374\374\374\377;;;\377\000\000\000\377\226\226\226\377\377"
  "\377\377\377\252\252\252\377\000\000\000\377\000\000\000\377\000\000\000\346\000\000\000\377\000\000"
  "\000\377\000\000\000\377\254\254\254\377\374\374\374\377\377\377\377\377\377\377"
  "\377\377\372\372\372\377\375\375\375\377\377\377\377\377\377\377\377\377"
  "\366\366\366\377\236\236\236\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377"
  "\255\255\255\377\376\376\376\377\377\377\377\377\376\376\376\377\376\376"
  "\376\377\377\377\377\377\373\373\373\377\235\235\235\377\000\000\000\377\000\000\000"
  "\377\256\256\256\377\376\376\376\377\377\377\377\377\377\377\377\377\377"
  "\377\377\377\376\376\376\377\255\255\255\377\000\000\000\377\000\000\000\377\000\000\000\377"
  "\322\322\322\377\377\377\377\377ddd\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000"
  "\000\377\000\000\000\377\000\000\000\377\000\000\000\377\201\201\201\377\364\364\364\377\377"
  "\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377"
  "\377\365\365\365\377\231\231\231\377\000\000\000\377\000\000\000\377\000\000\000\377RRR\377"
  "\002\002\002\377\000\000\000\377\000\000\000\377\000\000\000\346\000\000\000\377\000\000\000\377\000\000\000\377\000"
  "\000\000\377bbb\377\273\273\273\377\335\335\335\377\352\352\352\377\347\347\347"
  "\377\326\326\326\377\253\253\253\377CCC\377\000\000\000\377\000\000\000\377\000\000\000\377"
  "\000\000\000\377\000\000\000\377\000\000\000\377~~~\377\317\317\317\377\347\347\347\377\344"
  "\344\344\377\275\275\275\377^^^\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377"
  "\220\220\220\377\332\332\332\377\352\352\352\377\330\330\330\377\216\216"
  "\216\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\247\247\247\377\341\341"
  "\341\377\063\063\063\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000"
  "\000\000\377\000\000\000\377\000\000\000\377CCC\377\251\251\251\377\317\317\317\377\332\332"
  "\332\377\313\313\313\377\237\237\237\377:::\377\000\000\000\377\000\000\000\377\000\000\000"
  "\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\346\000\000\000\377"
  "\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000"
  "\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000"
  "\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000"
  "\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377"
  "\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000"
  "\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000"
  "\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000"
  "\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377"
  "\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\346\000\000\000\377\000\000\000\377\000"
  "\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000"
  "\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000"
  "\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377"
  "\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000"
  "\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000"
  "\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000"
  "\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377"
  "\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000"
  "\000\000\377\000\000\000\377\000\000\000\377\000\000\000\346\000\000\000\377\000\000\000\377\000\000\000\377\000\000"
  "\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000"
  "\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377"
  "\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000"
  "\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000"
  "\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000"
  "\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377"
  "\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000"
  "\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000"
  "\000\377\000\000\000\377\000\000\000\346\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000"
  "\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377"
  "\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000"
  "\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000"
  "\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000"
  "\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377"
  "\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000"
  "\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000"
  "\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000"
  "\377\000\000\000\346",
};

