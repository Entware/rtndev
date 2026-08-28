# SPDX-License-Identifier: GPL-2.0-only
#
# Copyright (C) 2023-2026 Entware

include $(TOPDIR)/rules.mk

PKG_NAME:=libjodycode
PKG_VERSION:=4.1.2
PKG_REV:=fdbea562be10051410dac8de3247e628d1047612
PKG_RELEASE:=1

PKG_SOURCE:=$(PKG_NAME)-$(PKG_VERSION).tar.bz2
PKG_SOURCE_SUBDIR:=$(PKG_NAME)-$(PKG_VERSION)
PKG_SOURCE_URL:=https://codeberg.org/jbruchon/libjodycode.git
PKG_SOURCE_PROTO:=git
PKG_SOURCE_VERSION:=$(PKG_REV)
PKG_MIRROR_HASH:=8c7cb61ccd48a9a3e628eebb60850a9b82c26e6847eb55eed0c1f9006da3bebb

PKG_INSTALL:=1

include $(INCLUDE_DIR)/package.mk

define Package/libjodycode
	SECTION:=libs
	CATEGORY:=Libraries
	TITLE:=Jody Bruchon library
	URL:=https://www.jodybruchon.com/software
	MAINTAINER:=Entware team, https://entware.net
	BUILDONLY:=1
endef

define Package/libjodycode/description
 Shared code used by several utilities written by Jody Bruchon.
endef

MAKE_VARS += PREFIX=/opt

define Build/InstallDev
	$(INSTALL_DIR) $(1)/opt/include $(1)/opt/lib
	$(CP) $(PKG_INSTALL_DIR)/opt/include/$(PKG_NAME).h $(1)/opt/include
	$(CP) $(PKG_INSTALL_DIR)/opt/lib/$(PKG_NAME).a $(1)/opt/lib
endef

$(eval $(call BuildPackage,libjodycode))
