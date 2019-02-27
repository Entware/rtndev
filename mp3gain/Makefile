#
# Copyright (C) 2011-2019 Entware
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#

include $(TOPDIR)/rules.mk

PKG_NAME:=mp3gain
PKG_VERSION:=1.6.2
PKG_RELEASE:=1

PKG_SOURCE:=$(PKG_NAME)-1_6_2-src.zip
PKG_SOURCE_URL:=@SF/$(PKG_NAME)/$(PKG_VERSION)
PKG_UNPACK:=unzip $(DL_DIR)/$(PKG_SOURCE) -d $(BUILD_DIR)/$(PKG_NAME)-$(PKG_VERSION)
PKG_HASH:=5cc04732ef32850d5878b28fbd8b85798d979a025990654aceeaa379bcc9596d

include $(INCLUDE_DIR)/package.mk

define Package/mp3gain
	SECTION:=sound
	CATEGORY:=Sound
	DEPENDS:=+libmpg123
	TITLE:=A free automatic mp3 volume normalizer
	URL:=http://mp3gain.sourceforge.net/
	MAINTAINER:=Entware team, https://entware.net
endef

define Package/mp3gain/description
 MP3Gain analyzes and adjusts mp3 files so that they have the same volume.
endef

define Package/mp3gain/install
	$(INSTALL_DIR) $(1)/opt/bin
	$(INSTALL_BIN) $(PKG_BUILD_DIR)/mp3gain $(1)/opt/bin
endef

$(eval $(call BuildPackage,mp3gain))
