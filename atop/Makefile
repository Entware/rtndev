#
# Copyright (C) 2018 Entware
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#

include $(TOPDIR)/rules.mk

PKG_NAME:=atop
PKG_VERSION:=2.3.0
PKG_RELEASE:=1a

PKG_SOURCE_URL:=http://www.atoptool.nl/download
PKG_SOURCE:=$(PKG_NAME)-$(PKG_VERSION).tar.gz
PKG_HASH:=73e4725de0bafac8c63b032e8479e2305e3962afbe977ec1abd45f9e104eb264

PKG_LICENSE:=GPL-2.0+
PKG_LICENSE_FILES:=COPYING

include $(INCLUDE_DIR)/package.mk

define Package/atop
  SECTION:=utils
  CATEGORY:=Utilities
  TITLE:=Atop is an ASCII full-screen performance monitor for Linux
  URL:=https://www.atoptool.nl/
  DEPENDS:=+zlib +libncurses +librt +libpthread
  MAINTAINER:=Entware team, https://entware.net
endef

define Package/atop/description
  Atop is an ASCII full-screen performance monitor for Linux
  that is capable of reporting the activity of all processes
  (even if processes have finished during the interval),
  daily logging of system and process activity for long-term
  analysis, highlighting overloaded system resources by
  using colors, etc. At regular intervals, it shows
  system-level activity related to the CPU, memory, swap,
  disks (including LVM) and network layers, and for every
  process (and thread) it shows e.g. the CPU utilization,
  memory growth, disk utilization, priority, username,
  state, and exit code.
endef

define Package/atop/install
	$(INSTALL_DIR) $(1)/opt/{bin,sbin}
	$(INSTALL_BIN) $(PKG_BUILD_DIR)/atop $(1)/opt/bin/
	$(INSTALL_BIN) $(PKG_BUILD_DIR)/atopacctd $(1)/opt/sbin/
	$(LN) ../bin/atop $(1)/opt/sbin/atopsar
	$(INSTALL_DIR) $(1)/opt/share/atop
	$(INSTALL_BIN) $(PKG_BUILD_DIR)/atop.daily $(1)/opt/share/atop/
	$(INSTALL_DIR) $(1)/opt/etc/init.d
	$(INSTALL_BIN) $(PKG_BUILD_DIR)/atop.init $(1)/opt/etc/init.d/S99atop
	$(INSTALL_DIR) $(1)/opt/var/lock/subsys
endef

$(eval $(call BuildPackage,atop))
