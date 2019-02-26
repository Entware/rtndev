#
# Copyright (C) 2011-2019 Entware
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#

include $(TOPDIR)/rules.mk

PKG_NAME:=chromaprint
PKG_VERSION:=1.4.3
PKG_REV:=ecd2edd73315530d4f9c1b1186aee24c63a7b6c2
PKG_RELEASE:=1

PKG_SOURCE:=$(PKG_NAME)-$(PKG_VERSION).tar.bz2
PKG_SOURCE_SUBDIR:=$(PKG_NAME)-$(PKG_VERSION)
PKG_SOURCE_URL:=https://github.com/acoustid/chromaprint.git
PKG_SOURCE_PROTO:=git
PKG_SOURCE_VERSION:=$(PKG_REV)

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
	$(INSTALL_DIR) $(1)/opt/lib
	$(INSTALL_BIN) $(PKG_INSTALL_DIR)/opt/lib/libchromaprint.so* $(1)/opt/lib
	$(INSTALL_DIR) $(1)/opt/bin
	$(INSTALL_BIN) $(PKG_INSTALL_DIR)/opt/bin/fpcalc $(1)/opt/bin
endef

$(eval $(call BuildPackage,chromaprint))
