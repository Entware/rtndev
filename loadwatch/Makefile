#
# Copyright (C) 2011-2019 Entware
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#
# Abandoned in 2003

include $(TOPDIR)/rules.mk

PKG_NAME:=loadwatch
PKG_VERSION:=1.0+1.1alpha1
PKG_RELEASE:=2

PKG_SOURCE:=$(PKG_NAME)_$(PKG_VERSION).orig.tar.gz
PKG_SOURCE_URL:=http://ftp.debian.org/debian/pool/main/l/loadwatch/
PKG_HASH:=2a2044346ed980b4eed971494e7a9c088e8473daf0f153db8e4469e2d9a072a9

PKG_FIXUP:=autoreconf
PKG_INSTALL:=1

PKG_BUILD_DIR:=$(BUILD_DIR)/$(PKG_NAME)-1.1

include $(INCLUDE_DIR)/package.mk

define Package/loadwatch
	SECTION:=utils
	CATEGORY:=Utilities
	SUBMENU:=CPU tools
	TITLE:=run processes only at acceptable system load
	URL:=http://loadwatch.sourceforge.net
	MAINTAINER:=Entware team, https://entware.net
endef

define Package/loadwatch/description
 loadwatch allows one or more processes to run only when the load on a machine is within
 certain bounds. The child processes are sent SIGSTOP when the machines load passes
 the high load mark. The processes are sent SIGCONT only after the machines load drops
 below the low load mark. The load is checked at a user definable interval.
endef

define Package/loadwatch/install
	$(INSTALL_DIR) $(1)/opt/bin
	$(INSTALL_BIN) $(PKG_INSTALL_DIR)/opt/bin/{loadwatch,lw-ctl} $(1)/opt/bin/
endef

$(eval $(call BuildPackage,loadwatch))
