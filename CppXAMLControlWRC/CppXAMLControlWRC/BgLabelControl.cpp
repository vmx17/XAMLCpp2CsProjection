#include "pch.h"
#include "BgLabelControl.h"
#if __has_include("BgLabelControl.g.cpp")
#include "BgLabelControl.g.cpp"
#endif

// To learn more about WinUI, the WinUI project structure,
// and more about our project templates, see: http://aka.ms/winui-project-info.

namespace winrt::CppXAMLControlWRC::implementation
{
    Microsoft::UI::Xaml::DependencyProperty BgLabelControl::m_labelProperty =
        Microsoft::UI::Xaml::DependencyProperty::Register(
            L"Label",
            winrt::xaml_typename<winrt::hstring>(),
            winrt::xaml_typename<CppXAMLControlWRC::BgLabelControl>(),
            Microsoft::UI::Xaml::PropertyMetadata{ winrt::box_value(L"default label"), Microsoft::UI::Xaml::PropertyChangedCallback{ &BgLabelControl::OnLabelChanged } }
    );

    void BgLabelControl::OnLabelChanged(Microsoft::UI::Xaml::DependencyObject const& d, Microsoft::UI::Xaml::DependencyPropertyChangedEventArgs const& /* e */)
    {
        if (CppXAMLControlWRC::BgLabelControl theControl{ d.try_as<CppXAMLControlWRC::BgLabelControl>() })
        {
            // Call members of the projected type via theControl.

            CppXAMLControlWRC::implementation::BgLabelControl* ptr{ winrt::get_self<CppXAMLControlWRC::implementation::BgLabelControl>(theControl) };
            // Call members of the implementation type via ptr.
        }
    }
}
