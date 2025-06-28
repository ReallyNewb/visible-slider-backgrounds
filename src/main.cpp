#include <Geode/Geode.hpp>
#include <Geode/modify/Slider.hpp>

#include <Geode/utils/cocos.hpp>

using namespace geode::prelude;

class $modify(NewSlider, Slider) {
public:
	bool init(CCNode* p0, SEL_MenuHandler p1, char const* p2, char const* p3, char const* p4, char const* p5, float p6) {
		if (!Slider::init(p0, p1, p2, p3, p4, p5, p6)) return false;

		auto failsafe = WeakRef(this);
		queueInMainThread([failsafe] {
			auto self = failsafe.lock();
			if (!self) return;
			auto main = self->getChildByType<CCSprite>(0);
			if (!main) return;
			auto bg = main->getChildByType<CCSprite>(0);
			if (!bg) return;

			auto nodeId = self->getID();

			if (nodeId == "position-slider") {
				auto visible = !Mod::get()->getSettingValue<bool>("ignore-editor-slider");
				bg->setPositionY(2.f);
				bg->setVisible(visible);
			} else {
				auto visible = !Mod::get()->getSettingValue<bool>("opposite-day");
				bg->setVisible(visible);   
			}
		});
		return true;
	}
};
