#
# Copyright (C) 2011-2019 Entware
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#
# Abandoned in 2010

include $(TOPDIR)/rules.mk

PKG_NAME:=mp3gain
PKG_VERSION:=1.5.2-r2
PKG_RELEASE:=1

PKG_SOURCE:=$(PKG_NAME)-1_5_2_r2-src.zip
PKG_SOURCE_URL:=@SF/$(PKG_NAME)/1.5.2
PKG_UNPACK:=unzip $(DL_DIR)/$(PKG_SOURCE) -d $(BUILD_DIR)/$(PKG_NAME)-$(PKG_VERSION)
PKG_HASH:=3378d32c8333c14f57622802f6a92b725f36ee45a6b181657b595b1b5d64260f

include $(INCLUDE_DIR)/package.mk

define Package/mp3gain
	SECTION:=sound
	CATEGORY:=Sound
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
