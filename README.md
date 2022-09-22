# XAMLCpp2CsProjection

This is a simple sample to confirm that XAML custom control made by C++/WinRT can be referred by C#.

Currently, this does NOT work.

This repository was made to "Ask Microsoft Q&A" but I'd like to get any help from many persons.

Previously I've made NetProjection repository but it became a little complicated. So I re-make this repository to use simpler samples.

## Motivation

Get performance with C++ and productivity with C#!!!
Here I intended to make moodern desktop app in C# but use DirectX with C++ (in future).

## Purpose of the program

**The purpose of this repository is to show _"BgLabelControl"_ in C# stub.**

- A library which content is _BgLabelControl_ from [here](https://learn.microsoft.com/en-us/windows/apps/winui/winui3/xaml-templated-controls-cppwinrt-winui-3?source=docs). The article just shows referring from in-project stubs. It's not usage of "library".
- Stubs refer and show _BgLabelControl_ defined in C++/WinRT and C#.
  - C# stub has not been supplied, yet. It will be placed in combination with projection project as separated solution.

## File structure

- Solution: "CppXAMLControlWRC.sln"
  - Project: "CppXAMLControlWRC.vcxproj": The target WRC that include _CppXAMLControlWRC::BgLabelControl_.
  - Project: "CppConsumeApp.vcxproj": Stab (in C++) that refers _BgLabelControl_ locally.

## Status

- 02/22/2022
  Build fails at C++stub in same solution. (reference by project/winmd.) Message is;
  `C2039    'CppXAMLControlWRC': is not a member of 'winrt'    CppConsumeApp`
WindowsAppSDK 1.1.5


## Reference

- [Build XAML controls with C++/WinRT](https://docs.microsoft.com/en-us/windows/apps/winui/winui3/xaml-templated-controls-cppwinrt-winui-3)
