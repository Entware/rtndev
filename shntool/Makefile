#
# Copyright (C) 2011-2021 Entware
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#
# Abandoned in 2009

include $(TOPDIR)/rules.mk

PKG_NAME:=shntool
PKG_VERSION:=3.0.10
PKG_RELEASE:=3

PKG_SOURCE:=$(PKG_NAME)-$(PKG_VERSION).tar.gz
PKG_SOURCE_URL:=http://shnutils.freeshell.org/shntool/dist/src
PKG_HASH:=74302eac477ca08fb2b42b9f154cc870593aec8beab308676e4373a5e4ca2102

PKG_INSTALL:=1

include $(INCLUDE_DIR)/package.mk

define Package/shntool
	SECTION:=sound
	CATEGORY:=Sound
	DEPENDS:=+libogg +libvorbis +libflac
	TITLE:=A multi-purpose wav data processing utility
	URL:=http://shnutils.freeshell.org/shntool/
	MAINTAINER:=Entware team, https://entware.net
endef

define Package/shntool/description
 shntool has native support for .wav files. If you want it to work with other
 lossless audio formats, you must have the appropriate helper program installed.
endef

CONFIGURE_VARS += \
	ac_cv_prog_FLAC="yes"

define Package/shntool/install
	$(INSTALL_DIR) $(1)/opt/bin
	$(CP) $(PKG_INSTALL_DIR)/opt/bin/* $(1)/opt/bin
endef

$(eval $(call BuildPackage,shntool))
