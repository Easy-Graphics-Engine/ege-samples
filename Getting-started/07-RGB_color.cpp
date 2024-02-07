/**
 *  Easy Graphics Engine (https://xege.org)
 *  RGB 颜色
 *
 *  预备知识:
 *          RGB 颜色由三个颜色分量组成，分别是红(Red), 绿(Green),蓝(Blue)，这三种颜
 *      色也称为色光三原色。RGB 颜色模式中每种颜色都可以由这三种颜色分量按不同比例
 *      混合而成。由于硬件的限制，目前 RGB 颜色每个分量的取值范围大多为 0~255(十六
 *      进制 0x00~0xFF), 数值越大，亮度越高，颜色也就越亮。三个颜色分量的值都为 0
 *      时为黑色，都为 255 时为白色。
 *          RGB 颜色常用十六进制颜色码(Hex)来表示: #RRGGBB，而在 EGE 中，可以用
 *      EGERGB(R, G, B) 宏来表示，传入RGB颜色的三个分量即可。
 *          在 EGE 中，颜色的类型为 color_t。
 *          以下为部分常见颜色的对应关系:
 *
 *    | 颜色 | 十六进制颜色码 | EGE 中颜色表示(十六进制) | EGE 中颜色表示(十进制) |
 *    |------|----------------|--------------------------|------------------------|
 *    | 纯白 |    #FFFFFF     | EGERGB(0xFF, 0xFF, 0xFF) | EGERGB(255, 255, 255)  |
 *    | 纯黑 |    #000000     | EGERGB(0x00, 0x00, 0x00) | EGERGB(  0,   0,   0)  |
 *    | 纯黄 |    #FFFF00     | EGERGB(0xFF, 0xFF, 0x00) | EGERGB(255, 255,   0)  |
 *    | 灰色 |    #808080     | EGERGB(0x80, 0x80, 0x80) | EGERGB(128, 128, 128)  |
 *    | 淡蓝 |    #87CEFA     | EGERGB(0x87, 0xCE, 0xFA) | EGERGB(135, 206, 250)  |
 *
 *  程序说明:
 *      使用不同的 RGB 颜色设置背景色。
 *
 *  相关函数及宏:
 *      宏 EGERGB(R, G, B): 将 R, G, B 三个颜色分量组合成 RGB 颜色值
 */

#include <graphics.h>

int main()
{
    // 初始化，窗口设置为 640x480 大小，禁用启动动画
    initgraph(640, 480, 0);

    // 设置背景色为白色
    setbkcolor(WHITE);
    delay_ms(1500);

    //设置背景色为淡蓝色
    setbkcolor(EGERGB(0x87, 0xCE, 0xFA));
    delay_ms(1500);

    //设置背景色为中绿松石色
    color_t color = EGERGB(0x48, 0xD1, 0xCC);
    setbkcolor(color);
    delay_ms(1500);

    closegraph();
    return 0;
}
