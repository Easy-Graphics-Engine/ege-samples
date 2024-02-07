/**
 *  Easy Graphics Engine (https://xege.org)
 *  简单绘图
 *
 *  预备知识:
 *      EGE 的普通绘图函数
 *
 *  程序说明:
 *      使用 EGE 的普通绘图函数绘制几个基本图形
 *
 *  相关函数:
 *      setfillcolor():     设置填充颜色
 *      -- bar():           绘制填充矩形  (无边框)
 *      -- fillpoly():      绘制填充多边形(有边框)
 *      -- fillellipse:     绘制填充椭圆  (有边框)
 */

#include <graphics.h>
#include <stdio.h>
#include <math.h>

int main()
{
    // 初始化，窗口设置为 640x480 大小，禁用启动画面
    initgraph(640, 360, 0);

    //设置深色背景
    setbkcolor(EGERGB(0x30, 0x30, 0x30));

    //设置线宽和前景色(会影响填充图形的边框、线条以及文本)
    setlinewidth(2.0f);
    setcolor(WHITE);

    int margin = 12;

    // 设置填充颜色为蓝色，绘制一个填充矩形
    setfillcolor(EGERGB(92, 167, 233));
    bar(20, 20, 280, 160);

    // 外面套一个矩形边框
    setcolor(EGERGB(235, 94, 67));
    rectangle(20 - margin, 20 - margin, 280 + margin, 160 + margin);

    // 设置前景色为绿色，绘制一个填充多边形
    const int polyPoints[3*2] = {   // 三个顶点，每个顶点占两个元素(x, y)
        160, 200,
         40, 320,
        280, 320,
    };
    setcolor(WHITE);
    setfillcolor(EGERGB(115, 201, 120));
    fillpoly(3, polyPoints);

    // 设置填充颜色为橙色，并绘制一个填充圆
    setcolor(WHITE);
    setfillcolor(EGERGB(235, 94, 67));
    fillellipse(500, 140, 100, 100);

    // 外面套一个 270° 的圆弧
    setcolor(YELLOW);
    ellipse(500, 140, 0, 270, 100 + margin, 100 + margin);

    // 设置前景色为黄色，并绘制一条直线
    setcolor(YELLOW);
    line(400, 300, 600, 300);


    // 暂停，等待用户按键
    getch();

    closegraph();
    return 0;
}
