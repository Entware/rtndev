#
# Copyright (C) 2011-2024 Entware
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#

include $(TOPDIR)/rules.mk

PKG_NAME:=limitcpu
PKG_VERSION:=3.1
PKG_RELEASE:=1

PKG_SOURCE:=cpulimit-$(PKG_VERSION).tar.gz
PKG_SOURCE_URL:=@SF/$(PKG_NAME)
PKG_HASH:=946994ec60f39f03095b89bd74e660b89c14c82aba7545669398e302bc7b234c

PKG_BUILD_DIR:=$(BUILD_DIR)/cpulimit-$(PKG_VERSION)

include $(INCLUDE_DIR)/package.mk

define Package/limitcpu
	SECTION:=utils
	CATEGORY:=Utilities
	SUBMENU:=CPU tools
	DEPENDS:=+librt
	TITLE:=CPU usage limiter
	URL:=http://limitcpu.sourceforge.net
	MAINTAINER:=Entware team, https://entware.net
endef

define Package/limitcpu/description
 LimitCPU is a program to throttle the CPU cycles used by other applications.
 It will monitor a process and make sure its CPU usage stays at or below
 a given percentage.
endef

define Package/limitcpu/install
	$(INSTALL_DIR) $(1)/opt/bin
	$(INSTALL_BIN) $(PKG_BUILD_DIR)/cpulimit $(1)/opt/bin
endef

$(eval $(call BuildPackage,limitcpu))
