#
# Copyright (C) 2011-2021 Entware
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#

include $(TOPDIR)/rules.mk

PKG_NAME:=chromaprint
PKG_VERSION:=1.5.1
PKG_REV:=5c3be6803856f25b11d1d704bac56e733b4fc997
PKG_RELEASE:=1

PKG_SOURCE:=$(PKG_NAME)-$(PKG_VERSION).tar.bz2
PKG_SOURCE_SUBDIR:=$(PKG_NAME)-$(PKG_VERSION)
PKG_SOURCE_URL:=https://github.com/acoustid/chromaprint.git
PKG_SOURCE_PROTO:=git
PKG_SOURCE_VERSION:=$(PKG_REV)
PKG_MIRROR_HASH:=4ee45223ddf86466e3424d11ea503a55c403ebf812afbeb6e2a60d35f753f8d5

include $(INCLUDE_DIR)/package.mk
include $(INCLUDE_DIR)/cmake.mk

define Package/chromaprint
	SECTION:=libs
	CATEGORY:=Libraries
	SUBMENU:=Sound
	DEPENDS:=+libffmpeg-full +libstdcpp
	TITLE:=audio fingerprint library
	URL:=https://github.com/acoustid/chromaprint
	MAINTAINER:=Entware team, https://entware.net
endef

define Package/chromaprint/description
 Chromaprint is an audio fingerprint library developed for the AcoustID project.
 It's designed to identify near-identical audio and the fingerprints it
 generates are as compact as possible to achieve that.
endef

CMAKE_OPTIONS += \
	-DBUILD_TOOLS=ON \
	-DBUILD_TESTS=OFF

TARGET_CFLAGS+=-fpermissive

define Build/InstallDev
	true
endef

define Package/chromaprint/install
	$(INSTALL_DIR) $(1)/opt/bin
	$(INSTALL_BIN) $(PKG_INSTALL_DIR)/opt/bin/fpcalc $(1)/opt/bin
	$(INSTALL_DIR) $(1)/opt/lib
	$(CP) $(PKG_INSTALL_DIR)/opt/lib/libchromaprint.so.* $(1)/opt/lib
endef

$(eval $(call BuildPackage,chromaprint))
