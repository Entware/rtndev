# SPDX-License-Identifier: GPL-2.0-only
#
# Copyright (C) 2011-2025 Entware

include $(TOPDIR)/rules.mk

PKG_NAME:=daemonize
PKG_VERSION:=1.7.8
PKG_REV:=18869a797dab12bf1c917ba3b4782fef484c407c
PKG_RELEASE:=2

PKG_SOURCE:=$(PKG_NAME)-$(PKG_VERSION).tar.bz2
PKG_SOURCE_SUBDIR:=$(PKG_NAME)-$(PKG_VERSION)
PKG_SOURCE_URL:=https://github.com/bmc/daemonize.git
PKG_SOURCE_PROTO:=git
PKG_SOURCE_VERSION:=$(PKG_REV)
PKG_MIRROR_HASH:=caabb35256661efcacb27e4cf3a0c9d70eb11054382590ea804eb44e36fe061d

include $(INCLUDE_DIR)/package.mk

define Package/daemonize
	SECTION:=utils
	CATEGORY:=Utilities
	TITLE:=runs a command as a daemon
	URL:=http://software.clapper.org/daemonize/
	MAINTAINER:=Entware team, https://entware.net
endef

define Package/daemonize/description
 daemonize is a command-line utility that runs a command as a Unix daemon.
endef

define Package/daemonize/install
	$(INSTALL_DIR) $(1)/opt/bin
	$(INSTALL_BIN) $(PKG_BUILD_DIR)/daemonize $(1)/opt/bin
endef

$(eval $(call BuildPackage,daemonize))
