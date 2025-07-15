// backup.c
int backup()
{
    string file;
    int result;
    mapping db, backup;
    string *keys_list;
    int i;
    string key;
    mixed val;

    if (!stringp(file = this_object()->query_save_file()))
        return 0;

    file = file + ".oo";
    assure_file(file + __SAVE_EXTENSION__);

    db = this_object()->query_entire_dbase();
    if (!mapp(db) || !sizeof(db))
        return 0;

    backup = ([]);
    keys_list = keys(db);

    for (i = 0; i < sizeof(keys_list); i++)
    {
        key = keys_list[i];
        val = db[key];

        // 过滤 object, function, buffer 类型字段
        if (objectp(val) || functionp(val) || bufferp(val))
        {
            backup[key] = val;
            this_object()->delete(key);
        }
    }

    result = save_object(file);

    // 恢复非法字段
    keys_list = keys(backup);
    for (i = 0; i < sizeof(keys_list); i++)
    {
        key = keys_list[i];
        this_object()->set(key, backup[key]);
        write("恢复字段："+key);
    }

    return result;
}