/**
 *  Easy Graphics Engine (https://xege.org)
 *  带透明通道的图像
 *
 *  预备知识:
 *
 *  程序说明:
 *      从带透明通道的图片文件(PNG, BMP等)中加载图像并进行绘制。
 *
 *  相关类型:
 *      PIMAGE: 图像指针
 *
 *  相关函数:
 *      newimage():             创建图像
 *      delimage():             销毁图像
 *      getimage():             获取图像
 *      putimage_withalpha():   绘制图像(使用透明通道)
 *
 *      更多函数查阅文档: https://xege.org/manual/api/font/index.htm
 */

#include <graphics.h>
#include <stdio.h>
#include <math.h>

int main()
{
    initgraph(600, 600, 0);
    setbkcolor(EGERGB(0x30, 0x30, 0x30));   //设置深色背景

    // 创建图像
    PIMAGE pimg = newimage();

    // 从图片文件加载图像 (图片文件相对路径为 "./res/drawable/17-image.png")
    getimage(pimg, "./res/drawable/17-image.png");

    // 绘制带透明通道的图像到窗口(0, 0)的位置
    putimage_withalpha(NULL, pimg, 0, 0);

    // 绘制完成，后续不会再使用此图像，将其销毁
    delimage(pimg);

    getch();

    closegraph();

    return 0;
}
