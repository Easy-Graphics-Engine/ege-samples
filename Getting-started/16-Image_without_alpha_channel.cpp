/**
 *  Easy Graphics Engine (https://xege.org)
 *  图像(无透明通道)
 *
 *  预备知识:
 *
 *
 *  程序说明:
 *      从图片文件(PNG, BMP, JPG等)中加载图像并进行绘制，绘制时忽略其透明通道，只使用 RGB 通道。
 *
 *  相关类型:
 *      PIMAGE: 图像指针
 *
 *  相关函数:
 *      newimage():             创建图像
 *      delimage():             销毁图像
 *      getimage():             获取图像
 *      putimage():             绘制图像(忽略透明通道)
 *
 *      更多函数查阅文档: https://xege.org/manual/api/font/index.htm
 */

#include <graphics.h>
#include <stdio.h>
#include <math.h>

int main()
{
    initgraph(384, 683, 0);
    setbkcolor(EGERGB(0x30, 0x30, 0x30));   //设置深色背景

    // 创建图像
    PIMAGE pimg = newimage();

    // 从图片文件加载图像 (图片文件相对路径为 "./res/drawable/16-image.png")
    getimage(pimg, "./res/drawable/16-image.png");

    // 绘制图像(忽略其透明通道)到窗口(x, y)的位置
    int x = 0, y = 0;
    putimage(x, y, pimg);

    // 绘制完成，后续不会再使用此图像，将其销毁
    delimage(pimg);

    getch();

    closegraph();

    return 0;
}


