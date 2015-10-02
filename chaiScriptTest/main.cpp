//
//  main.cpp
//  chaiScriptTest
//
//  Created by wood on 15/9/5.
//  Copyright (c) 2015年 wood. All rights reserved.
//

#include <iostream>
#include <chaiscript/chaiscript.hpp>
#include <chaiscript/chaiscript_stdlib.hpp>

double function(int i, double j)
{
    return i * j;
}

int main()
{
    chaiscript::ChaiScript chai(chaiscript::Std_Lib::library());
    chai.add(chaiscript::fun(&function), "function");
    chai.eval_file("HelloWorld.chai");
    using namespace chaiscript;
    std::function<double ()> TestChai = chai.eval<std::function<double ()> >("TestChai");
    double d = TestChai();         // 调用脚本函数
    //double d = chai.eval<double>("HelloWorld.chai");
    printf("%f",d);
}