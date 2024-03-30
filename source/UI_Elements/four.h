/* GIMP RGBA C-Source image dump (four.c) */

static const struct {
  unsigned int 	 width;
  unsigned int 	 height;
  unsigned int 	 bytes_per_pixel; /* 2:RGB16, 3:RGB, 4:RGBA */ 
  unsigned char	 pixel_data[32 * 21 * 4 + 1];
} four = {
  32, 21, 4,
  "\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000"
  "\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000"
  "\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000"
  "\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377"
  "\000\000\000\377\000\000\000\377\000\000\000\352\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000"
  "\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000"
  "\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000"
  "\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377"
  "\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\352\000\000\000\377\000"
  "\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000"
  "\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000"
  "\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377"
  "\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000"
  "\000\000\377\000\000\000\352\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000"
  "\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000"
  "\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377"
  "\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000"
  "\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\352\000\000\000\377\000\000\000\377\000\000"
  "\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000"
  "\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\033\033\033\377\027\027"
  "\027\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000"
  "\377\000\000\000\377\000\000\000\377\014\014\014\377sss\377$$$\377\000\000\000\377\000\000\000\377\000"
  "\000\000\352\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000"
  "\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\211\211"
  "\211\377\345\345\345\377\375\375\375\377\374\374\374\377\334\334\334\377"
  "lll\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\011\011"
  "\011\377\326\326\326\377\377\377\377\377\262\262\262\377\000\000\000\377\000\000\000\377"
  "\000\000\000\352\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000"
  "\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\215\215\215\377"
  "\375\375\375\377\356\356\356\377\271\271\271\377\275\275\275\377\363\363"
  "\363\377\365\365\365\377YYY\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000"
  "\000\000\377\250\250\250\377\377\377\377\377\377\377\377\377\271\271\271\377"
  "\000\000\000\377\000\000\000\377\000\000\000\352\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000"
  "\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377)))\377"
  "\361\361\361\377\352\352\352\377===\377\000\000\000\377\000\000\000\377ddd\377\372\372"
  "\372\377\315\315\315\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377ggg\377\372"
  "\372\372\377\317\317\317\377\377\377\377\377\271\271\271\377\000\000\000\377\000"
  "\000\000\377\000\000\000\352\000\000\000\377\000\000\000\377NNN\377\225\225\225\377\000\000\000\377\000"
  "\000\000\377\000\000\000\377\000\000\000\377\"\"\"\377\264\264\264\377NNN\377\231\231\231"
  "\377\377\377\377\377\220\220\220\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000"
  "\377\321\321\321\377\371\371\371\377$$$\377\000\000\000\377\000\000\000\377\026\026\026"
  "\377\342\342\342\377\364\364\364\377SSS\377\377\377\377\377\271\271\271\377"
  "\000\000\000\377\000\000\000\377\000\000\000\352\000\000\000\377\000\000\000\377\240\240\240\377\377\377"
  "\377\377\261\261\261\377\000\000\000\377\000\000\000\377\007\007\007\377\311\311\311\377\377"
  "\377\377\377~~~\377\307\307\307\377\372\372\372\377\037\037\037\377\000\000\000\377"
  "\000\000\000\377\000\000\000\377\000\000\000\377\256\256\256\377\377\377\377\377iii\377\000\000"
  "\000\377\000\000\000\377\266\266\266\377\377\377\377\377\233\233\233\377'''\377\377"
  "\377\377\377\271\271\271\377\000\000\000\377\000\000\000\377\000\000\000\352\000\000\000\377\000\000"
  "\000\377\010\010\010\377\317\317\317\377\375\375\375\377\200\200\200\377\036\036"
  "\036\377\315\315\315\377\377\377\377\377\266\266\266\377\000\000\000\377\324\324"
  "\324\377\353\353\353\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377"
  "\241\241\241\377\377\377\377\377|||\377\000\000\000\377uuu\377\374\374\374\377"
  "\326\326\326\377\000\000\000\377'''\377\377\377\377\377\271\271\271\377\000\000\000\377"
  "\000\000\000\377\000\000\000\352\000\000\000\377\000\000\000\377\000\000\000\377\066\066\066\377\354\354\354"
  "\377\357\357\357\377\331\331\331\377\376\376\376\377\253\253\253\377\000\000"
  "\000\377\000\000\000\377\324\324\324\377\353\353\353\377\000\000\000\377\000\000\000\377\000\000"
  "\000\377\000\000\000\377\000\000\000\377\245\245\245\377\377\377\377\377sss\377???\377"
  "\353\353\353\377\364\364\364\377QQQ\377\000\000\000\377'''\377\377\377\377\377"
  "\271\271\271\377\000\000\000\377\000\000\000\377\000\000\000\352\000\000\000\377\000\000\000\377\000\000\000"
  "\377\000\000\000\377\202\202\202\377\377\377\377\377\377\377\377\377\250\250\250"
  "\377\000\000\000\377\000\000\000\377\000\000\000\377\315\315\315\377\366\366\366\377\000\000\000"
  "\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\270\270\270\377\377\377\377"
  "\377OOO\377\315\315\315\377\377\377\377\377\372\372\372\377\361\361\361\377"
  "\361\361\361\377\361\361\361\377\377\377\377\377\365\365\365\377\340\340"
  "\340\377^^^\377\000\000\000\352\000\000\000\377\000\000\000\377\000\000\000\377(((\377\332\332\332"
  "\377\377\377\377\377\377\377\377\377\267\267\267\377\000\000\000\377\000\000\000\377"
  "\000\000\000\377\262\262\262\377\377\377\377\377WWW\377\000\000\000\377\000\000\000\377\000\000"
  "\000\377\000\000\000\377\327\327\327\377\366\366\366\377\003\003\003\377\241\241\241\377"
  "\307\307\307\377\314\314\314\377\314\314\314\377\314\314\314\377\315\315"
  "\315\377\377\377\377\377\360\360\360\377\322\322\322\377QQQ\377\000\000\000\352"
  "\000\000\000\377\000\000\000\377(((\377\325\325\325\377\376\376\376\377\246\246\246\377"
  "\325\325\325\377\376\376\376\377\214\214\214\377\000\000\000\377\000\000\000\377uuu\377"
  "\377\377\377\377\261\261\261\377\000\000\000\377\000\000\000\377\000\000\000\377UUU\377\373"
  "\373\373\377\323\323\323\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000"
  "\000\377\000\000\000\377'''\377\377\377\377\377\271\271\271\377\000\000\000\377\000\000\000\377"
  "\000\000\000\352\000\000\000\377)))\377\335\335\335\377\376\376\376\377\251\251\251\377"
  "\000\000\000\377???\377\354\354\354\377\365\365\365\377^^^\377\000\000\000\377\000\000\000"
  "\377\337\337\337\377\371\371\371\377\222\222\222\377\034\034\034\377ccc\377"
  "\342\342\342\377\376\376\376\377~~~\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000"
  "\000\377\000\000\000\377\000\000\000\377,,,\377\377\377\377\377\271\271\271\377\000\000\000\377"
  "\000\000\000\377\000\000\000\352\000\000\000\377\204\204\204\377\376\376\376\377\245\245\245"
  "\377\000\000\000\377\000\000\000\377\000\000\000\377ooo\377\371\371\371\377\331\331\331\377"
  "\000\000\000\377\000\000\000\377___\377\356\356\356\377\377\377\377\377\376\376\376\377"
  "\377\377\377\377\375\375\375\377\257\257\257\377\000\000\000\377\000\000\000\377\000\000"
  "\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377###\377\376\376\376\377\267"
  "\267\267\377\000\000\000\377\000\000\000\377\000\000\000\352\000\000\000\377\000\000\000\377NNN\377\000\000"
  "\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\201\201\201\377\223\223\223"
  "\377\000\000\000\377\000\000\000\377\000\000\000\377\064\064\064\377\237\237\237\377\277\277\277"
  "\377\260\260\260\377kkk\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000"
  "\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\207\207\207\377SSS\377\000\000\000"
  "\377\000\000\000\377\000\000\000\352\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377"
  "\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000"
  "\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000"
  "\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000"
  "\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\352\000\000\000\377\000\000\000\377"
  "\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000"
  "\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000"
  "\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000"
  "\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377"
  "\000\000\000\352\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000"
  "\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000"
  "\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000"
  "\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377"
  "\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\352",
};

