# SPDX-License-Identifier: GPL-2.0-only
#
# Copyright (C) 2025-2026 Entware

# https://github.com/Entware/Entware/issues/994 (as deps)

include $(TOPDIR)/rules.mk

PKG_NAME:=libqb
PKG_VERSION:=2.0.9
PKG_RELEASE:=1

PKG_SOURCE:=$(PKG_NAME)-$(PKG_VERSION).tar.gz
PKG_SOURCE_URL:=https://codeload.github.com/ClusterLabs/libqb/tar.gz/refs/tags/v$(PKG_VERSION)?
PKG_HASH:=499379e9d7c684c7919373eb041ca5bffd2bdec74ee41a8c489f8be925d0498b

PKG_MAINTAINER:=Entware team, https://entware.net
PKG_LICENSE:=LGPL-2.1-or-later
PKG_LICENSE_FILES:=COPYING

PKG_FIXUP:=autoreconf
PKG_INSTALL:=1

include $(INCLUDE_DIR)/package.mk
include $(INCLUDE_DIR)/nls.mk

define Package/libqb
  SECTION:=libs
  CATEGORY:=Libraries
  TITLE:=An IPC library for high performance servers
  URL:=http://clusterlabs.github.io/libqb
endef

define Package/libqb/description
  libqb provides high-performance, reusable features for
 client-server architecture, such as logging, tracing, inter-process
 communication (IPC), and polling.
endef

define Build/InstallDev
	$(INSTALL_DIR) $(1)/opt/include
	$(CP) $(PKG_INSTALL_DIR)/opt/include/qb $(1)/opt/include
	$(INSTALL_DIR) $(1)/opt/lib
	$(CP) $(PKG_INSTALL_DIR)/opt/lib/libqb.{a,so*} $(1)/opt/lib
	$(INSTALL_DIR) $(1)/opt/lib/pkgconfig
	$(CP) $(PKG_INSTALL_DIR)/opt/lib/pkgconfig/libqb.pc $(1)/opt/lib/pkgconfig
endef

define Package/libqb/install
	$(INSTALL_DIR) $(1)/opt/lib
	$(CP) $(PKG_INSTALL_DIR)/opt/lib/libqb.so* $(1)/opt/lib
	$(INSTALL_DIR) $(1)/opt/sbin
	$(INSTALL_BIN) $(PKG_INSTALL_DIR)/opt/sbin/qb-blackbox $(1)/opt/sbin
endef

$(eval $(call BuildPackage,libqb))
