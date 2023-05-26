#
# Copyright (C) 2011-2021 Entware
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#

include $(TOPDIR)/rules.mk

PKG_NAME:=iotop
PKG_VERSION:=0.6
PKG_RELEASE:=1

PKG_SOURCE_PROTO:=git
PKG_SOURCE_VERSION:=1bfb3bc70febb1ffb95146b6dcd65257228099a3
PKG_SOURCE_URL:=https://repo.or.cz/iotop.git
PKG_MIRROR_HASH:=2f3c7951c946d5269bbe6523718ad53d1e8a093e59a5b7be16a12c59158ed6e3

include $(TOPDIR)/feeds/packages/lang/python/pypi.mk
include $(INCLUDE_DIR)/package.mk
include $(TOPDIR)/feeds/packages/lang/python/python3-package.mk

define Package/iotop
	SECTION:=admin
	CATEGORY:=Administration
	TITLE:=iotop watches I/O usage information output by the Linux kernel
	URL:=http://guichaz.free.fr/iotop/
	DEPENDS:=+python3-ctypes +python3-ncurses
endef

define Package/iotop/description
 Iotop is a Python program with a top like UI used to show of behalf of
 which process is the I/O going on.
endef

define Package/iotop/install
	$(INSTALL_DIR) $(1)/opt/sbin
	$(INSTALL_BIN) $(PKG_INSTALL_DIR)/opt/bin/iotop $(1)/opt/sbin
	$(INSTALL_DIR) $(1)$(PYTHON3_PKG_DIR)
	$(CP) $(PKG_INSTALL_DIR)$(PYTHON3_PKG_DIR)/* $(1)$(PYTHON3_PKG_DIR)
	$(call Python3/FixShebang,$(1)/opt/sbin/iotop)
endef

$(eval $(call Py3Package,iotop))
$(eval $(call BuildPackage,iotop))
