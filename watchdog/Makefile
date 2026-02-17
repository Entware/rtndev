# SPDX-License-Identifier: GPL-2.0-only
#
# Copyright (C) 2025 Entware

# https://github.com/Entware/Entware/issues/955

include $(TOPDIR)/rules.mk

PKG_NAME:=watchdog
PKG_VERSION:=5.16
PKG_RELEASE:=1

PKG_SOURCE:=$(PKG_NAME)-$(PKG_VERSION).tar.gz
PKG_SOURCE_URL:=@SF/watchdog
PKG_HASH:=5483b40349446d50672be7b547011eb6c9d0ea28f92ecaa46437cd2570b7bf36

PKG_MAINTAINER:=Entware team, https://entware.net
PKG_LICENSE:=GPL-2.0-only
PKG_LICENSE_FILES:=COPYING

PKG_INSTALL:=1

include $(INCLUDE_DIR)/package.mk

define Package/watchdog
  SECTION:=admin
  CATEGORY:=Administration
  TITLE:=a software watchdog daemon
  URL:=https://watchdog.sourceforge.io
endef

define Package/watchdog/description
  Watchdog is a daemon that checks if your system is still working.
endef

define Package/watchdog/conffiles
/opt/etc/watchdog.conf
endef

CONFIGURE_ARGS += \
	--with-configfile=/opt/etc/watchdog.conf \
	--with-test-bin-path=/opt/etc/watchdog.d \
	--with-pidfile=/opt/var/run/watchdog.pid \
	--with-ka_pidfile=/opt/var/run/wd_keepalive.pid \
	--with-randomseed=/opt/var/run/random-seed

define Package/watchdog/install
	$(INSTALL_DIR) $(1)/opt/etc/watchdog.d
	$(INSTALL_CONF) $(PKG_INSTALL_DIR)/opt/etc/watchdog.conf $(1)/opt/etc
	$(INSTALL_DIR) $(1)/opt/sbin
	$(INSTALL_BIN) $(PKG_INSTALL_DIR)/opt/sbin/watchdog $(1)/opt/sbin
	$(INSTALL_BIN) $(PKG_INSTALL_DIR)/opt/sbin/wd_{identify,keepalive} \
		$(1)/opt/sbin
endef

$(eval $(call BuildPackage,watchdog))
