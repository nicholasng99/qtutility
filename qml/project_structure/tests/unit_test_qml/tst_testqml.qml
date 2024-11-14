import QtQuick
import QtQuick.Controls

import QtTest
import FirstPlugin

TestCase {
    name: "TestQML"

    function initTestCase() {
    }

    function cleanupTestCase() {
    }

    function test_case1() {
        compare(1 + 1, 2, "sanity check");
        verify(true);
    }

    Component {
        id: component2

        MyItemControls {
            id: rect1
            componentBackground: "red"
        }

    }

    function test_case2() {
        // component.module_function1();
        // component2.rect1.color = "red"

        compare(1 + 1, 2, "sanity check");
        verify(true);
    }
}
