#include <stdio.h>
#include "env.h"
#include "utils.h"
#include "files.h"

const char* envCreateWorkspace (const char *name) {
    /* int i; */
    const char* home = getHome();
    char path[512];

    snprintf(path, sizeof(path), "%s/.frost/unpaked", home);

    /* for (i = 0; i < 100; ++i) { */
    /*     // Проверить наличие такого же имени среди уже существующих */
    /*     if (name_exists) { // "ИМЯ"+"(i+1)" */

    /*     } else { */
    /*         // "ИМЯ"+"i" */
    /*     } */
    /* } */
    /* if (i >= 100) { */
    /*     // Ошибка мол сори ти щото много імен однакових наделал */
    /* } */
    /* // Составить meta воркспейса */
    /* /1* int fd = filesOpenFRW( путь до файла с метой ); *1/ */
    /* // Добавить в json */
    /* filesClose(fd); */
    /* // Создать директорию, вмонтировать tmpfs */
    /* // Путь до симлинка = g_config.simlinks_path || "getHome()/" */
    /* // Создать симлинк */
    /* // Ничего не ретурн, команды ничего не возвращают, кроме exit(ошибка) */
    const char* test_name = "qwerty"; int counter = 0;
    UniqueFileName userdata;
    userdata.name = test_name;
    userdata.counter = &counter;
    filesListByType(path, ".meta", uniqueFileName, &userdata);
    return "name";
}
