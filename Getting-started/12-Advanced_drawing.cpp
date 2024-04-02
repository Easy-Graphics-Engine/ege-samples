/**
 *  Easy Graphics Engine (https://xege.org)
 *  高级绘图
 *
 *  预备知识:
 *          EGE 的高级绘图函数支持 Anti-Aliasing (抗锯齿, 让图形边缘更平滑)，使
 *      用 ARGB 颜色，可以进行颜色混合，绘制半透明图形。
 *          EGE 中的高级绘图函数以 ege_ 为前缀。
 *          可以使用 ege_enable_aa() 开启抗锯齿，只对高级绘图函数有效。
 *          高级绘图函数中填充图形不带边框，这个跟普通绘图函数有所区别。
 *
 *  程序说明:
 *      在不抗锯齿和抗锯齿两种设置下分别使用高级绘图函数绘图同样的图形，了解抗锯齿的效果。
 *
 *  相关函数:
 *      宏 EGEARGB(A, R, G, B): 将不透明度 A 和 R, G, B 三个颜色分量组合成 ARGB 颜色
 *      宏 EGEACOLOR(A, RGB):   将不透明度 A 和一个 RGB 颜色组合成一个 ARGB 颜色
 *      ege_enable_aa():        抗锯齿开启关闭设置
 *      -- ege_line():          绘制直线
 *      -- ege_rectangle():     绘制矩形线框
 * 		-- ege_ellipse():		绘制椭圆线框
 * 		-- ege_drawpoly():		绘制多边形线框
 *      -- ege_fillrect():      绘制填充矩形
 *      -- ege_fillellipse():   绘制填充圆
 *      -- ege_fillpoly():      绘制填充多边形
 *
 *      更多函数查阅文档: https://xege.org/manual/api/draw/index.htm
 */

// 设置目标平台最低为 Windows Vista，以便能使用 SetProcessDPIAware() 函数
#define WINVER       0X0600
#define _WIN32_WINNT 0x0600

#include <windows.h>
#include <graphics.h>
#include <stdio.h>
#include <math.h>

void advancedDraw(float x, float y, float width, float height, const char* text);   // 高级绘图
color_t linearInterp(color_t rgb0, color_t rgb1, float t);                          // RGB 颜色线性插值

int main()
{
    SetProcessDPIAware();
    // 初始化图形环境
	int winWidth = 800, winHeight = winWidth / 2;
    initgraph(winWidth, winHeight, 0);

    //设置深色背景
    setbkcolor(EGERGB(0x30, 0x30, 0x30));
    setfont(24, 0, "SimHei");
    settextjustify(CENTER_TEXT, CENTER_TEXT);
    setbkmode(TRANSPARENT);

    cleardevice();

    // 关闭抗锯齿，使用高级绘图函数进行绘图
    ege_enable_aa(false);
    advancedDraw(0, 0, winWidth / 2.0f, winHeight, "Disable Anti-Aliasing");

    // 开启抗锯齿，使用高级绘图函数进行绘图
    ege_enable_aa(true);
	advancedDraw(winWidth / 2.0f, 0, winWidth / 2.0f, winHeight, "Enable Anti-Aliasing");

    // 暂停，等待用户按键
    getch();

    closegraph();
    return 0;
}

// 高级绘图
void advancedDraw(float x, float y, float width, float height, const char* text)
{
    // 颜色条:[0] = 白色, [1] = 蓝色
    color_t colorbar[2] = {(color_t)EGEARGB(0, 247, 250, 255), (color_t)EGEARGB(0, 10, 50, 109)};

    float radius = (float)width * 3 / 4;
    const int n = 6;

    for (int i = 0; i < n; i++) {
        ege_point vertex[3];
        vertex[0].x = x;
        vertex[0].y = y;
        vertex[1].x = x + radius * cos((PI / 2.0) * i / n);
        vertex[1].y = y + radius * sin((PI / 2.0) * i / n);
        vertex[2].x = x + radius * cos((PI / 2.0) * (i+1) / n);
        vertex[2].y = y + radius * sin((PI / 2.0) * (i+1) / n);

        setfillcolor(linearInterp(colorbar[0], colorbar[1], (float)i / n));
        ege_fillpoly(3, vertex);
    }

    float cx = x + radius;
    float cy = y + radius;
    float cr = 48.0f;

    setfillcolor(colorbar[0]);
    ege_fillellipse(cx - cr, cy - cr - cr, cr * 2, cr * 2);

    setcolor(WHITE);
    xyprintf(x + width / 2.0f, y + height * 7.0f / 8.0f, text);
}

// 在 rgb0 与 rgb1 之间做线性插值(rgb0-->rgb1), t范围:[0.0, 1.0],
color_t linearInterp(color_t rgb0, color_t rgb1, float t)
{
    unsigned char r = (unsigned char)(EGEGET_R(rgb0) + t * (int)(EGEGET_R(rgb1) - EGEGET_R(rgb0)) + 0.5f);
    unsigned char g = (unsigned char)(EGEGET_G(rgb0) + t * (int)(EGEGET_G(rgb1) - EGEGET_G(rgb0)) + 0.5f);
    unsigned char b = (unsigned char)(EGEGET_B(rgb0) + t * (int)(EGEGET_B(rgb1) - EGEGET_B(rgb0)) + 0.5f);

    return EGERGB(r, g, b);
}


