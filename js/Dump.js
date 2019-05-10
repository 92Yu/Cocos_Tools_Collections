Dump

this is used for output multidimensional array.
--------------------------------------------------------


gl.dumpIdx = 0;
gl.dumpStr = '';
gl._dumpAppend = function(obj, name, tStr)
{
    gl.dumpIdx++;
    var dis = "    ";
    var dntStr = "\n";
    //有几个\t制表符号
    for (var i = 0; i < gl.dumpIdx; i++){
        dntStr += dis;
    }
    var tstr = dntStr + name + ':{';
    var dntStrr = dntStr + dis;
    for (var ty in obj) {
        var type_ = typeof(obj[ty]);
        var str = '';
        if (type_ == "function")
            str = dntStrr + ty + ": function,";
        else if (type_ == "object") {
            str = gl._dumpAppend(obj[ty], ty);
        } else {
            str = dntStrr + ty + ": " + obj[ty] + ",";
        }
        tstr += str;
    }
    tstr = tstr + dntStr + "  }\n";
    return tstr;
}

var dump = function(obj)
{
    gl.dumpStr = '';
    gl.dumpIdx = 0;
    gl.dumpStr = "Object = {";
    for (var ty in obj) {
        var type_ = typeof(obj[ty]);
        var str = '';
        if (type_ == "function")
            str = "\n    " + ty + ": function,";
        else if (type_ == "object") {
            str = gl._dumpAppend(obj[ty], ty);
        } else {
            str = "\n    " + ty + ": " + obj[ty] + ",";
        }
        gl.dumpStr += str;
    }
    gl.dumpStr += "  }";

    cc.log(gl.dumpStr);
}
