# SPDX-License-Identifier: GPL-2.0-only
#
# Copyright (C) 2025 Entware

# https://github.com/Entware/Entware/issues/994

include $(TOPDIR)/rules.mk

PKG_NAME:=corosync-qdevice
PKG_VERSION:=3.0.3
PKG_RELEASE:=1

PKG_SOURCE:=$(PKG_NAME)-$(PKG_VERSION).tar.gz
PKG_SOURCE_URL:=https://codeload.github.com/corosync/corosync-qdevice/tar.gz/refs/tags/v$(PKG_VERSION)?
PKG_HASH:=8ed730f998c0bff65a15983b9859ff9a44dfba1a76fda45b040c10d8c13e5384

PKG_MAINTAINER:=Entware team, https://entware.net
PKG_LICENSE:=BSD-3-Clause
PKG_LICENSE_FILES:=LICENSE

PKG_FIXUP:=autoreconf
PKG_INSTALL:=1

include $(INCLUDE_DIR)/package.mk

define Package/corosync-qdevice
  SECTION:=net
  CATEGORY:=Network
  TITLE:=The Corosync Cluster Engine Qdevice
  URL:=https://github.com/corosync/corosync-qdevice
  DEPENDS:=+libcorosync +nspr +nss-utils
  EXTRA_DEPENDS:=bash, coreutils-stat, procps-ng-ps, procps-ng-w
endef

define Package/corosync-qdevice/description
  corosync-qdevice is a daemon running on each node of a cluster.
endef

define Package/corosync-qdevice/install
	$(INSTALL_DIR) $(1)/opt/bin
	$(INSTALL_BIN) $(PKG_INSTALL_DIR)/opt/bin/corosync-qnetd* $(1)/opt/bin
	$(INSTALL_DIR) $(1)/opt/etc
	$(CP) $(PKG_INSTALL_DIR)/opt/etc/corosync $(1)/opt/etc
#	$(INSTALL_DIR) $(1)/opt/etc/init.d
#	$(INSTALL_BIN) $(PKG_INSTALL_DIR)/opt/etc/init.d/corosync-qdevice \
#		$(1)/opt/etc/init.d/S20corosync-qdevice
#	$(INSTALL_BIN) $(PKG_INSTALL_DIR)/opt/etc/init.d/corosync-qnetd \
#		$(1)/opt/etc/init.d/S20corosync-qnetd
	$(INSTALL_DIR) $(1)/opt/sbin
	$(INSTALL_BIN) $(PKG_INSTALL_DIR)/opt/sbin/corosync-qdevice* $(1)/opt/sbin
	$(INSTALL_DIR) $(1)/opt/var/corosync-q{device,netd}
endef

#define Package/corosync-qdevice/postinst
##!/bin/sh

#corosync-qnetd-certutil -i
#corosync-qdevice-net-certutil -i -c /opt/etc/corosync/qnetd/nssdb/qnetd-cacert.crt
#endef

$(eval $(call BuildPackage,corosync-qdevice))
