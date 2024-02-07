/**
 *  Easy Graphics Engine (https://xege.org)
 *  设置填充颜色
 *
 *  程序说明:
 *          如矩形，圆等封闭图形会在平面上占据一块区域，填充区域内部所使用
 *      的颜色我们称之为填充颜色(Fill color)，这种内部填充的封闭称之为填充
 *      图形。
 *          初始化后，填充颜色默认为 #000000(黑色)。
 *          调用 setfillcolor() 设置填充颜色后，会一直生效到下一次填充颜色
 *      改变为止。设置填充颜色只会影响后面绘制的图形，在设置之前已经绘制出
 *      的图形，其颜色不会改变，所以在绘制图形前，需要提前设置好填充颜色。
 *
 *  相关函数:
 *      setfillcolor():     设置填充颜色
 *      -- bar():           绘制填充矩形  (无边框)
 *      -- fillpoly():      绘制填充多边形(有边框)
 *      -- fillellipse:     绘制填充椭圆  (有边框)
 */

#include <graphics.h>
#include <stdio.h>

int main()
{
    // 初始化，窗口设置为 640x480 大小，禁用启动画面
    initgraph(640, 360, 0);

    //设置深色背景
    setbkcolor(EGERGB(0x30, 0x30, 0x30));

    //设置线宽和前景色(会影响填充图形的边框)
    setlinewidth(2.0f);
    setcolor(WHITE);

    // 设置填充颜色为蓝色，绘制一个填充矩形
    setfillcolor(EGERGB(92, 167, 233));
    bar(20, 20, 280, 160);

    //设置前景色为绿色，绘制一个填充多边形
    setfillcolor(EGERGB(115, 201, 120));
    const int points[3*2] = {   // 三个顶点，每个顶点占两个元素(x, y)
        160, 200,
         40, 320,
        280, 320,
    };
    fillpoly(3, points);

    //设置填充颜色为橙色，并绘制一个填充圆
    setfillcolor(EGERGB(235, 94, 67));
    fillellipse(500, 140, 100, 100);

    // 暂停，等待用户按键
    getch();

    closegraph();
    return 0;
}
