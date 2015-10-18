#
# Copyright (C) 2011-2015 Entware
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#
# (c) Cezary Jackiewicz <cezary@eko.one.pl>

include $(TOPDIR)/rules.mk

PKG_NAME:=idle3-tools
PKG_REV=21
PKG_VERSION:=0.9.3-r$(PKG_REV)
PKG_RELEASE:=1

PKG_SOURCE_PROTO:=svn
PKG_SOURCE_VERSION:=$(PKG_REV)
PKG_SOURCE_SUBDIR:=$(PKG_NAME)-$(PKG_VERSION)
PKG_SOURCE_URL:=http://svn.code.sf.net/p/$(PKG_NAME)/code/trunk
PKG_SOURCE:=$(PKG_NAME)-$(PKG_VERSION).tar.gz

include $(INCLUDE_DIR)/package.mk

define Package/idle3-tools
	SECTION:=utils
	CATEGORY:=Utilities
	SUBMENU:=disc
	TITLE:=WD idle3 timer settings
	URL:=http://idle3-tools.sourceforge.net/
	MAINTAINER:=Entware team, entware.wl500g.info
endef

define Package/idle3-tools/description
 This linux/unix utility can be used to remove or set the infamous idle3 timer
 found on recent Western Digital Hard Disk Drives.
endef

define Package/idle3-tools/install
	$(INSTALL_DIR) $(1)/opt/bin
	$(INSTALL_BIN) $(PKG_BUILD_DIR)/idle3ctl $(1)/opt/bin/
endef

$(eval $(call BuildPackage,idle3-tools))
