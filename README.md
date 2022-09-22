# How can I use XAML custom control in Windows Runtime Conponent?

This is a simple program to refer XAML custom control in Windows Runtime Conponent.

Currently, this does NOT work.

This repository was made to "Ask Microsoft Q&A" but I'd like to get any help from many persons.

Previously I've made ["NetProjection" repository](https://github.com/vmx17/NetProjection) but it became a little complicated. So I re-make this repository to build simpler samples.

## Motivation

Get performance with C++ and productivity with C#! Yeah, it's a Microsoft recommended way, but hard.

I intended to make modern desktop application in C# but use DirectX in C++.

But, before going there, I stucked using XAML custom control in WRC. Though there are some related documents [here](https://learn.microsoft.com/en-us/windows/apps/winui/winui3/xaml-templated-controls-cppwinrt-winui-3?source=docs) and [there](https://learn.microsoft.com/en-us/windows/apps/develop/platform/csharp-winrt/net-projection-from-cppwinrt-component), they avoids using XAML control nor make as separated library. I'm keep asking, "Is this possible?" but no answer obtained, yet.

## Purpose of the program

**The final purpose of this repository is to show XAML control in WRC on C# stub.**

Isn't it simple? Then I make two projects. One is library contains a XAML custom control. The other is a stub that refers the library and show/consume the XAML control.

I'd like to go in two steps below.

1. make library in C++/WinRT and make stub also in C++/WinRT.
2. make library in C++/WinRT and make stub in C#.

Now I'm in step 1.<br>
Between step 1 and 2, there might be a .Net 6's restriction, that we must make NuGet package. It also a hard way for debugging.

I'll use Microsoft's example _"BgLabelControl"_ as XAML control.
I would like to make the library as independent solution.


## File structure

- Solution: "CppXamlWRC": contains the _"BgLabelControl"_.
- Solution: "StubCpp": contains C++/WinRT stub to use the library.

Currently no C# items are provided.

## Status

- 09/22/2022
  Reference by project(*.winmd). Build fails at C++ stub. The output is;
  ```
  1>XamlTypeInfo.g.cpp 
  1>D:\Source\GitHub\XAMLCpp2CsProjection\StubCpp\StubCpp\Generated Files\XamlTypeInfo.g.cpp(179,28): error C2039: 'CppXamlWRC': is not a member of 'winrt'
  ```

## Error reproduction
- Open _CppXamlWRC\CppXamlWRC.sln_
- Restore NuGet packages.
- bbuild the solution in x64/release or x64/debug.
- Close the solution.
- Open _StubCpp\StubCpp.sln_
- Restore NuGet packages.
- build the solution in the same condition of _CppXamlWRC_.

I think these solutions can be unified... Sorry for inconvenience.

## Reference

- [Build XAML controls with C++/WinRT](https://docs.microsoft.com/en-us/windows/apps/winui/winui3/xaml-templated-controls-cppwinrt-winui-3)
