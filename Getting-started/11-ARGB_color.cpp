/**
 *  Easy Graphics Engine (https://xege.org)
 *  ARGB 颜色
 *
 *  预备知识:
 *          ARGB 颜色由一个不透明度(Alpha)和 RGB 的三个颜色分量组成。
 *          透明度 Alpha 表示 RGB 颜色的不透明度，用于颜色之间混合时颜色所占的比例，
 *      范围为 0% ~ 100%。0% 表示完全透明，100% 表示完全不透明。通常用 0 ~ 255 对应
 *      0% ~ 100%。
 *          ARGB 颜色的十六进制颜色码(Hex)为: #AARRGGBB。在 EGE 中，可以用 EGEARGB(A, R, G, B)
 *      宏来表示，传入不透明度和颜色的四个分量即可。
 *          RGB 颜色在 ARGB 中对应不透明度为 100% 的颜色，即不与其他颜色混合。
 *          对应关系: EGERGB(R, G, B) -->  EGEARGB(255, R, G, B)
 *          ARGB 颜色可以由 一个 alpha 值和 RGB 颜色构造: EGEACOLOR(alpha, RGB)
 *
 *  程序说明:
 *          使用 RGB 相同、alpha 不同的 ARGB 颜色绘制一组格子，查看在不透明度不同的情况下，格子颜色
 *      与背景混合后的最终颜色。
 *
 *  相关函数及宏:
 *      宏 EGEARGB(A, R, G, B): 将不透明度 A 和 R, G, B 三个颜色分量组合成 ARGB 颜色
 *      宏 EGEACOLOR(A, RGB):   将不透明度 A 和一个 RGB 颜色组合成一个 ARGB 颜色
 *      ege_fillrect():         绘制矩形
 */

#include <graphics.h>

int main()
{
    initgraph(640, 480, 0);

    setbkcolor(EGEARGB(255, 40, 44, 52));   // 设置暗色背景色

    color_t color = EGERGB(135, 206, 250);  // 淡蓝色

    int gridSide = 80;              // 格子边长
    int rowCnt = 480 / gridSide;    // 行数
    int colCnt = 640 / gridSide;    // 列数
    int padding = 4;                // 内部填充边距

    for (int row = 0; row < rowCnt; row++) {
        for (int col = 0; col < colCnt; col++) {
            // 计算格子对应的透明度
            int alpha = (255 * row / (rowCnt - 1) +  255 * col / (colCnt - 1)) / 2;

            // 修改 ARGB 中的透明度，并设置填充颜色
            setfillcolor(EGEACOLOR(alpha, color));

            // 计算格子位置
            int x = 640 * col / colCnt + padding;
            int y = 480 * row / rowCnt + padding;
            int width  = gridSide - 2 * padding;
            int height = gridSide - 2 * padding;

            // 对应位置上绘制一个矩形
            ege_fillrect(x, y, width, height);
        }
    }

    getch();

    closegraph();
    return 0;
}
