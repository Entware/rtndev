# SPDX-License-Identifier: GPL-2.0-only
#
# Copyright (C) 2025-2026 Entware

# https://github.com/Entware/Entware/issues/994

include $(TOPDIR)/rules.mk

PKG_NAME:=corosync
PKG_VERSION:=3.1.10
PKG_RELEASE:=1

PKG_SOURCE:=$(PKG_NAME)-$(PKG_VERSION).tar.gz
PKG_SOURCE_URL:=https://codeload.github.com/corosync/corosync/tar.gz/refs/tags/v$(PKG_VERSION)?
PKG_HASH:=03c55b984380bdb68ecd8d0f9cb1f9f0c2a7e6e7b7f437becc33e9a804018340

PKG_MAINTAINER:=Entware team, https://entware.net
PKG_LICENSE:=BSD-3-Clause
PKG_LICENSE_FILES:=LICENSE

PKG_FIXUP:=autoreconf
PKG_INSTALL:=1

include $(INCLUDE_DIR)/package.mk

define Package/corosync/Default
  TITLE:=The Corosync Cluster Engine
  URL:=https://corosync.github.io/corosync
endef

define Package/libcorosync
  $(call Package/corosync/Default)
  SECTION:=lib
  CATEGORY:=Libraries
  DEPENDS:=+libqb
endef

define Package/corosync
  $(call Package/corosync/Default)
  SECTION:=net
  CATEGORY:=Network
  DEPENDS:=+libcorosync +libknet +libreadline +libstatgrab
endef

define Package/corosync/description
  The Corosync Cluster Engine and Application Programming Interfaces.
endef

Package/libcorosync/description=$(Package/corosync/description)

define Package/corosync/conffiles
/opt/etc/corosync/corosync.conf
endef

CONFIGURE_ARGS += \
	--enable-monitoring \
	--enable-vqsim

define Build/InstallDev
	$(INSTALL_DIR) $(1)/opt/include
	$(CP) $(PKG_INSTALL_DIR)/opt/include/corosync $(1)/opt/include
	$(INSTALL_DIR) $(1)/opt/lib
	$(CP) $(PKG_INSTALL_DIR)/opt/lib/lib*.{a,so*} $(1)/opt/lib
	$(INSTALL_DIR) $(1)/opt/lib/pkgconfig
	$(CP) $(PKG_INSTALL_DIR)/opt/lib/pkgconfig/*.pc $(1)/opt/lib/pkgconfig
endef

define Package/libcorosync/install
	$(INSTALL_DIR) $(1)/opt/lib
	$(CP) $(PKG_INSTALL_DIR)/opt/lib/lib*.so* $(1)/opt/lib
endef

define Package/corosync/install
	$(INSTALL_DIR) $(1)/opt/bin
	$(INSTALL_BIN) $(PKG_INSTALL_DIR)/opt/bin/corosync-* $(1)/opt/bin
	$(INSTALL_DIR) $(1)/opt/etc
	$(CP) $(PKG_INSTALL_DIR)/opt/etc/{corosync,logrotate.d} $(1)/opt/etc
	$(CP) ./files/corosync.conf $(1)/opt/etc/corosync
#	$(INSTALL_DIR) $(1)/opt/etc/init.d
#	$(INSTALL_BIN) $(PKG_INSTALL_DIR)/opt/etc/init.d/corosync \
#		$(1)/opt/etc/init.d/S20corosync
#	$(INSTALL_BIN) $(PKG_INSTALL_DIR)/opt/etc/init.d/corosync-notifyd \
#		$(1)/opt/etc/init.d/S23corosync-notifyd
	$(INSTALL_DIR) $(1)/opt/sbin
	$(INSTALL_BIN) $(PKG_INSTALL_DIR)/opt/sbin/corosync* $(1)/opt/sbin
#	$(INSTALL_DIR) $(1)/opt/share
#	$(CP) $(PKG_INSTALL_DIR)/opt/share/snmp $(1)/opt/share
	$(INSTALL_DIR) $(1)/opt/var/{lib,log}/corosync
endef

$(eval $(call BuildPackage,libcorosync))
$(eval $(call BuildPackage,corosync))
