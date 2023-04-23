#include "dataconfig.h"
#include <QDebug>

DataConfig::DataConfig(QObject *parent)
    : QObject{parent}
{
    int array1[4][4] = {
        {1, 1, 1, 1},
        {1, 1, 0, 1},
        {1, 0, 0, 0},
        {1, 1, 0, 1}
    };

    QVector<QVector<int>> levelData;
    for(int i = 0; i < 4; ++i){
        QVector<int> temp;
        for(int j = 0; j < 4; ++j){
            temp.emplace_back(array1[i][j]);
        }
        levelData.emplace_back(temp);
    }
    mData.insert(1, levelData);

    int array2[4][4] = { {1, 0, 1, 1},
                         {0, 0, 1, 1},
                         {1, 1, 0, 0},
                         {1, 1, 0, 1}} ;

    levelData.clear();
    for(int i = 0 ; i < 4;i++)
    {
        QVector<int>temp;
        for(int j = 0 ; j < 4;j++)
        {
            temp.push_back(array2[i][j]);
        }
        levelData.push_back(temp);
    }

    mData.insert(2,levelData);



    int array3[4][4] = {  {0, 0, 0, 0},
                          {0, 1, 1, 0},
                          {0, 1, 1, 0},
                          {0, 0, 0, 0}} ;
    levelData.clear();
    for(int i = 0 ; i < 4;i++)
    {
        QVector<int>temp;
        for(int j = 0 ; j < 4;j++)
        {
            temp.push_back(array3[i][j]);
        }
        levelData.push_back(temp);
    }

    mData.insert(3,levelData);


    int array4[4][4] = {   {0, 1, 1, 1},
                           {1, 0, 0, 1},
                           {1, 0, 1, 1},
                           {1, 1, 1, 1}} ;
    levelData.clear();
    for(int i = 0 ; i < 4;i++)
    {
        QVector<int>temp;
        for(int j = 0 ; j < 4;j++)
        {
            temp.push_back(array4[i][j]);
        }
        levelData.push_back(temp);
    }

    mData.insert(4,levelData);


    int array5[4][4] = {  {1, 0, 0, 1},
                          {0, 0, 0, 0},
                          {0, 0, 0, 0},
                          {1, 0, 0, 1}} ;
    levelData.clear();
    for(int i = 0 ; i < 4;i++)
    {
        QVector<int>temp;
        for(int j = 0 ; j < 4;j++)
        {
            temp.push_back(array5[i][j]);
        }
        levelData.push_back(temp);
    }

    mData.insert(5,levelData);


    int array6[4][4] = {   {1, 0, 0, 1},
                           {0, 1, 1, 0},
                           {0, 1, 1, 0},
                           {1, 0, 0, 1}} ;
    levelData.clear();
    for(int i = 0 ; i < 4;i++)
    {
        QVector<int>temp;
        for(int j = 0 ; j < 4;j++)
        {
            temp.push_back(array6[i][j]);
        }
        levelData.push_back(temp);
    }

    mData.insert(6,levelData);


    int array7[4][4] = {   {0, 1, 1, 1},
                           {1, 0, 1, 1},
                           {1, 1, 0, 1},
                           {1, 1, 1, 0}} ;
    levelData.clear();
    for(int i = 0 ; i < 4;i++)
    {
        QVector<int>temp;
        for(int j = 0 ; j < 4;j++)
        {
            temp.push_back(array7[i][j]);
        }
        levelData.push_back(temp);
    }

    mData.insert(7,levelData);

    int array8[4][4] = {  {0, 1, 0, 1},
                          {1, 0, 0, 0},
                          {0, 0, 0, 1},
                          {1, 0, 1, 0}} ;
    levelData.clear();
    for(int i = 0 ; i < 4;i++)
    {
        QVector<int>temp;
        for(int j = 0 ; j < 4;j++)
        {
            temp.push_back(array8[i][j]);
        }
        levelData.push_back(temp);
    }

    mData.insert(8,levelData);

    int array9[4][4] = {   {1, 0, 1, 0},
                           {1, 0, 1, 0},
                           {0, 0, 1, 0},
                           {1, 0, 0, 1}} ;
    levelData.clear();
    for(int i = 0 ; i < 4;i++)
    {
        QVector<int>temp;
        for(int j = 0 ; j < 4;j++)
        {
            temp.push_back(array9[i][j]);
        }
        levelData.push_back(temp);
    }

    mData.insert(9,levelData);



    int array10[4][4] = {  {1, 0, 1, 1},
                           {1, 1, 0, 0},
                           {0, 0, 1, 1},
                           {1, 1, 0, 1}} ;
    levelData.clear();
    for(int i = 0 ; i < 4;i++)
    {
        QVector<int>temp;
        for(int j = 0 ; j < 4;j++)
        {
            temp.push_back(array10[i][j]);
        }
        levelData.push_back(temp);
    }

    mData.insert(10,levelData);


    int array11[4][4] = {  {0, 1, 1, 0},
                           {1, 0, 0, 1},
                           {1, 0, 0, 1},
                           {0, 1, 1, 0}} ;
    levelData.clear();
    for(int i = 0 ; i < 4;i++)
    {
        QVector<int>temp;
        for(int j = 0 ; j < 4;j++)
        {
            temp.push_back(array11[i][j]);
        }
        levelData.push_back(temp);
    }

    mData.insert(11,levelData);

    int array12[4][4] = {  {0, 1, 1, 0},
                           {0, 0, 0, 0},
                           {1, 1, 1, 1},
                           {0, 0, 0, 0}} ;
    levelData.clear();
    for(int i = 0 ; i < 4;i++)
    {
        QVector<int>temp;
        for(int j = 0 ; j < 4;j++)
        {
            temp.push_back(array12[i][j]);
        }
        levelData.push_back(temp);
    }

    mData.insert(12,levelData);


    int array13[4][4] = {    {0, 1, 1, 0},
                             {0, 0, 0, 0},
                             {0, 0, 0, 0},
                             {0, 1, 1, 0}} ;
    levelData.clear();
    for(int i = 0 ; i < 4;i++)
    {
        QVector<int>temp;
        for(int j = 0 ; j < 4;j++)
        {
            temp.push_back(array13[i][j]);
        }
        levelData.push_back(temp);
    }

    mData.insert(13,levelData);

    int array14[4][4] = {    {1, 0, 1, 1},
                             {0, 1, 0, 1},
                             {1, 0, 1, 0},
                             {1, 1, 0, 1}} ;
    levelData.clear();
    for(int i = 0 ; i < 4;i++)
    {
        QVector<int>temp;
        for(int j = 0 ; j < 4;j++)
        {
            temp.push_back(array14[i][j]);
        }
        levelData.push_back(temp);
    }

    mData.insert(14,levelData);


    int array15[4][4] = {   {0, 1, 0, 1},
                            {1, 0, 0, 0},
                            {1, 0, 0, 0},
                            {0, 1, 0, 1}} ;
    levelData.clear();
    for(int i = 0 ; i < 4;i++)
    {
        QVector<int>temp;
        for(int j = 0 ; j < 4;j++)
        {
            temp.push_back(array15[i][j]);
        }
        levelData.push_back(temp);
    }

    mData.insert(15,levelData);


    int array16[4][4] = {   {0, 1, 1, 0},
                            {1, 1, 1, 1},
                            {1, 1, 1, 1},
                            {0, 1, 1, 0}} ;
    levelData.clear();
    for(int i = 0 ; i < 4;i++)
    {
        QVector<int>temp;
        for(int j = 0 ; j < 4;j++)
        {
            temp.push_back(array16[i][j]);
        }
        levelData.push_back(temp);
    }

    mData.insert(16,levelData);

    int array17[4][4] = {  {0, 1, 1, 1},
                           {0, 1, 0, 0},
                           {0, 0, 1, 0},
                           {1, 1, 1, 0}} ;
    levelData.clear();
    for(int i = 0 ; i < 4;i++)
    {
        QVector<int>temp;
        for(int j = 0 ; j < 4;j++)
        {
            temp.push_back(array17[i][j]);
        }
        levelData.push_back(temp);
    }

    mData.insert(17,levelData);


    int array18[4][4] = { {0, 0, 0, 1},
                          {0, 0, 1, 0},
                          {0, 1, 0, 0},
                          {1, 0, 0, 0}} ;
    levelData.clear();
    for(int i = 0 ; i < 4;i++)
    {
        QVector<int>temp;
        for(int j = 0 ; j < 4;j++)
        {
            temp.push_back(array18[i][j]);
        }
        levelData.push_back(temp);
    }

    mData.insert(18,levelData);

    int array19[4][4] = {   {0, 1, 0, 0},
                            {0, 1, 1, 0},
                            {0, 0, 1, 1},
                            {0, 0, 0, 0}} ;
    levelData.clear();
    for(int i = 0 ; i < 4;i++)
    {
        QVector<int>temp;
        for(int j = 0 ; j < 4;j++)
        {
            temp.push_back(array19[i][j]);
        }
        levelData.push_back(temp);
    }

    mData.insert(19,levelData);

    int array20[4][4] = {  {0, 0, 0, 0},
                           {0, 0, 0, 0},
                           {0, 0, 0, 0},
                           {0, 0, 0, 0}} ;
    levelData.clear();
    for(int i = 0 ; i < 4;i++)
    {
        QVector<int>temp;
        for(int j = 0 ; j < 4;j++)
        {
            temp.push_back(array20[i][j]);
        }
        levelData.push_back(temp);
    }

    mData.insert(20,levelData);


    //测试数据
    //    for( QMap<int, QVector< QVector<int> > >::iterator it = mData.begin();it != mData.end();it++ )
    //    {
    //         for(QVector< QVector<int> >::iterator it2 = (*it).begin(); it2!= (*it).end();it2++)
    //         {
    //            for(QVector<int>::iterator it3 = (*it2).begin(); it3 != (*it2).end(); it3++ )
    //            {
    //                qDebug() << *it3 ;
    //            }
    //         }
    //         qDebug() << endl;
    //    }
}
