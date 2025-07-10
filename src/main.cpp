#include <Geode/Geode.hpp>
#include <Geode/modify/Slider.hpp>

class $modify(NewSlider, Slider) {
public:
	bool init(cocos2d::CCNode* p0, cocos2d::SEL_MenuHandler p1, char const* p2, char const* p3, char const* p4, char const* p5, float p6) {
		if (!Slider::init(p0, p1, p2, p3, p4, p5, p6)) return false;

		auto failsafe = geode::WeakRef(this);
		geode::queueInMainThread([failsafe] {
			auto self = failsafe.lock();
			if (!self) return;
			auto main = self->getChildByType<cocos2d::CCSprite>(0);
			if (!main) return;
			auto bg = main->getChildByType<cocos2d::CCSprite>(0);
			if (!bg) return;

			auto nodeId = self->getID();
			bool moveDown = nodeId == "position-slider" || geode::cast::typeinfo_cast<GJScaleControl*>(self->getParent());

			if (moveDown) bg->setPositionY(2.f);

			if (nodeId == "position-slider") {
				bg->setVisible(!geode::Mod::get()->getSettingValue<bool>("ignore-editor-slider"));
			} else {
				bg->setVisible(!geode::Mod::get()->getSettingValue<bool>("opposite-day"));   
			}
		});
		return true;
	}
};
