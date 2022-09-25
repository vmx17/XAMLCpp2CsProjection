# How can I use XAML custom control in Windows Runtime Component?

This is a simple program to refer XAML custom control in Windows Runtime Component.

Currently, only C++ stub works, C# stub show something but just a blank.

This repository was made to "Ask Question" in [Microsoft Q&A](https://learn.microsoft.com/en-us/answers/questions/1019298/how-can-i-use-xaml-custom-control-in-windows-runti.html) but I'd like to get any help from many persons.

Previously I've made ["NetProjection" repository](https://github.com/vmx17/NetProjection) but it became a little complicated. So I re-make this repository to build simpler samples.

## Motivation

Get performance with C++ and productivity with C#! Yeah, it's a Microsoft recommended way, but hard way especially for enterprise application.

I intended to make modern desktop application in C# but use DirectX in C++.

But, before going there, I stucked using XAML custom control in WRC. Though there are some related documents [here](https://learn.microsoft.com/en-us/windows/apps/winui/winui3/xaml-templated-controls-cppwinrt-winui-3?source=docs) and [there](https://learn.microsoft.com/en-us/windows/apps/develop/platform/csharp-winrt/net-projection-from-cppwinrt-component), they avoids using XAML control nor make as separated library. I'm keep asking, "Is this possible?" but no answer obtained, yet.

## Purpose of the program

**The final purpose of this repository is to show XAML control in WRC on C# stub.**

Isn't it simple? Then I make two projects. One is library contains a XAML custom control. The other is a stub that refers the library and show/consume the XAML control.

I'd like to go in two steps below.

1. make library in C++/WinRT and make stub also in C++/WinRT.
2. make library in C++/WinRT and make stub in C#.

Now I'm in step 2.<br>
Between step 1 and 2, there might be a .Net 6's restriction, that we must make NuGet package. Using NuGet package is also a hard way for debugging.

I'll use Microsoft's example _"BgLabelControl"_ as XAML control.
I would like to make the library as independent solution.


## File structure

- Solution: "CppXamlWRC": contains two projects.
  - "CppXamlWRC": An WRC project which include famous XAML custom control _"BgLabelControl"_.
  - "WRC2CsProjection": A projection project of "CppXamlWRC" to C# that makes NuGet package named as "CppXamlWRC.0.1.0-prerelease.nupkg". (The version number may vary.)
- Solution: "StubCpp": contains C++/WinRT stub to use the library.
- Solution: "StubCs": contains C#/WinRT stub to use the library.

The build directory "_build" is made at just under top directory.

Currently no C# items are provided.

## Status

- 09/24/2022
  - fix C++(App) - C++(WRC) reference issue and can build/run without errors. "Pch.h" and "App.xaml" were the key.
  - Add WRC projection project from C++ to C#. Add C# stub, "StubCs".
  - If the property "Height" and "Width" specified, there seems a blank. So it could refer something but default form/color/text is not shown correctly.
- 09/22/2022<br>
  Now I'm checking App.xaml of stub project. Modification seems to make some difference but same as before. 
- 09/22/2022<br>
  Reference by project(*.winmd). Build fails at C++ stub. The output is;
  ```
  1>XamlTypeInfo.g.cpp 
  1>D:\Source\GitHub\XAMLCpp2CsProjection\StubCpp\StubCpp\Generated Files\XamlTypeInfo.g.cpp(179,28): error C2039: 'CppXamlWRC': is not a member of 'winrt'
  ```

## Reproducing Error
- Open _CppXamlWRC\CppXamlWRC.sln_
- Restore NuGet packages.
- build the solution in x64/release.
- Close the solution.
- Open _StubCs\StubCs.sln_
- Restore NuGet packages.
- build the solution in in x64/release or x64/debug.

I think these solutions can be unified... Sorry for inconvenience.

## Reference

- [Build XAML controls with C++/WinRT](https://docs.microsoft.com/en-us/windows/apps/winui/winui3/xaml-templated-controls-cppwinrt-winui-3)
- [Generate a C# projection from a C++/WinRT component, distribute as a NuGet for .NET apps](https://learn.microsoft.com/en-us/windows/apps/develop/platform/csharp-winrt/net-projection-from-cppwinrt-component)
- [Walkthrough—Create a C#/WinRT component, and consume it from C++/WinRT](https://learn.microsoft.com/en-us/windows/apps/develop/platform/csharp-winrt/create-windows-runtime-component-cswinrt)
- [Walkthrough—Create a C# component with WinUI 3 controls, and consume it from a C++/WinRT app that uses the Windows App SDK](https://learn.microsoft.com/en-us/windows/apps/develop/platform/csharp-winrt/create-winrt-component-winui-cswinrt)
