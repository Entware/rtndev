#
# Copyright (C) 2011-2021 Entware
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#

include $(TOPDIR)/rules.mk

PKG_NAME:=chromaprint
PKG_VERSION:=1.5.0
PKG_REV:=516e3b31c7fa6e822035ea3b3e31f9c7f51ef4b6
PKG_RELEASE:=2

PKG_SOURCE:=$(PKG_NAME)-$(PKG_VERSION).tar.bz2
PKG_SOURCE_SUBDIR:=$(PKG_NAME)-$(PKG_VERSION)
PKG_SOURCE_URL:=https://github.com/acoustid/chromaprint.git
PKG_SOURCE_PROTO:=git
PKG_SOURCE_VERSION:=$(PKG_REV)
PKG_MIRROR_HASH:=178d0058efc6700afafddb7f294c53cc5b2ff77a9bb9c5a26110d1f625790905

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
	-DBUILD_TOOLS=ON

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
