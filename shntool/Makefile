#
# Copyright (C) 2011-2019 Entware
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#
# Abandoned in 2009

include $(TOPDIR)/rules.mk

PKG_NAME:=shntool
PKG_VERSION:=3.0.10
PKG_RELEASE:=1

PKG_SOURCE:=$(PKG_NAME)-$(PKG_VERSION).tar.gz
PKG_SOURCE_URL:=http://www.etree.org/shnutils/shntool/dist/src
PKG_INSTALL:=1

include $(INCLUDE_DIR)/package.mk

define Package/shntool
	SECTION:=sound
	CATEGORY:=Sound
	TITLE:=A multi-purpose wav data processing utility
	URL:=http://www.etree.org/shnutils/shntool/
	DEPENDS:=+libogg +libvorbis +libflac
endef

define Package/shntool/description
 shntool has native support for .wav files. If you want it to work with other lossless audio formats,
 you must have the appropriate helper program installed.
endef

CONFIGURE_ARGS+= \
	--disable-nls \
	--disable-static

define Package/shntool/install
	$(INSTALL_DIR) $(1)/opt/bin
	$(CP) $(PKG_INSTALL_DIR)/opt/bin/* $(1)/opt/bin
endef

$(eval $(call BuildPackage,shntool))
