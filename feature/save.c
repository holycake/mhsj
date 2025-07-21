// 递归检查函数
mixed filter_value(mixed val)
{
    string t;
    mapping new_map;
    mixed *new_arr;
    mixed k, v, filtered_v;

    t = typeof(val);
    if (t == "function" || t == "buffer" || t == "symbol" ||
        t == "class" || t == "unknown")
    {
        //debug_message(sprintf("跳过值，类型=%s，值=%O", t, val));
        return 0; // 使用 0 表示无效值
    }
    else if (t == "mapping")
    {
        new_map = ([]);
        foreach (k, v in val)
        {
            filtered_v = filter_value(v); // 直接递归调用
            if (filtered_v != 0)
                new_map[k] = filtered_v;
        }
        return sizeof(new_map) ? new_map : 0;
    }
    else if (t == "array")
    {
        new_arr = ({});
        foreach (v in val)
        {
            filtered_v = filter_value(v); // 直接递归调用
            if (filtered_v != 0)
                new_arr += ({ filtered_v });
        }
        return sizeof(new_arr) ? new_arr : 0;
    }
    return val; // 合法类型直接返回
}

// 主保存函数
int save()
{
    string file, key, t, err, dump, *illegal_keys;
    mapping db, safe_db;
    mixed val;
    int result;

    // 获取保存文件名
    if (!stringp(file = this_object()->query_save_file()))
        return 0;

    // 确保文件路径存在
    assure_file(file + __SAVE_EXTENSION__);

    // 获取当前 dbase
    db = this_object()->query_entire_dbase();
    if (!mapp(db) || !sizeof(db))
        return 0;

    // 调试：打印原始 dbase
    //debug_message(sprintf("原始 dbase: %O", db));
    debug_message(sprintf("开始保存数据文件: %s", file));

    // 初始化安全 dbase 和非法键列表
    safe_db = ([]);
    illegal_keys = ({});

    // 过滤 db 中的键值对
    foreach (key, val in db)
    {
        t = typeof(val);
        if (t == "function" || t == "buffer" || t == "symbol" ||
            t == "class" || t == "unknown")
        {
            //debug_message(sprintf("跳过 key=%s，类型=%s，值=%O", key, t, val));
            illegal_keys += ({ key });
            continue;
        }

        // 递归检查嵌套结构
        val = filter_value(val);
        if (val == 0)
        {
            //debug_message(sprintf("跳过 key=%s，因递归检查发现非法类型，值=%O", key, val));
            illegal_keys += ({ key });
            continue;
        }

        // 验证序列化
        err = catch(dump = save_variable(([ key : val ])));
        if (err || !stringp(dump))
        {
            //debug_message(sprintf("❌ 无法序列化 key=%s，类型=%s，错误=%s，值=%O", key, t, err, val));
            illegal_keys += ({ key });
            continue;
        }

        safe_db[key] = val;
    }

    // 调试：打印 safe_db 内容
    //debug_message(sprintf("保存前的 safe_db: %O", safe_db));

    // 清空原始 dbase
    this_object()->delete_all_dbase();

    // 删除所有非法键
    foreach (key in illegal_keys)
    {
        this_object()->delete(key);
        debug_message(sprintf("删除非法 key=%s", key));
    }

    // 设置过滤后的 dbase
    this_object()->set_dbase(safe_db);

    // 调试：验证 dbase 内容
    //debug_message(sprintf("设置后的 dbase: %O", this_object()->query_entire_dbase()));

    // 尝试保存
    result = save_object(file);
    debug_message(sprintf("数据文件%s保存完毕: %i", file, result));
    return result;
}

// 恢复函数（保持不变）
int restore()
{
    string file;
    if (stringp(file = this_object()->query_save_file()))
        return restore_object(file);
    return 0;
}