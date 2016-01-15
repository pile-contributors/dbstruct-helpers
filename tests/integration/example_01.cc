/**
 * \file tests/integration/example_01.cc
 * \brief GUI example using a text-only standard model
 *
 * The example does not use the list delegate (GroupListDelegate).
 */

#include "../testhelpers.h"

#include <QString>
#include <QApplication>

/* ------------------------------------------------------------------------- */
int main (int argc, char *argv[])
{
    QApplication a(argc, argv);

    int result = a.exec();

    return result;
}
/* ========================================================================= */
