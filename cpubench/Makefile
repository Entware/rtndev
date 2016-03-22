#
# Copyright (C) 2011-2016 Entware
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#

include $(TOPDIR)/rules.mk

PKG_NAME:=cpubench
PKG_VERSION:=0.6
PKG_RELEASE:=2

include $(INCLUDE_DIR)/package.mk

define Package/cpubench
	SECTION:=utils
	CATEGORY:=Utilities
	SUBMENU:=CPU tools
	TITLE:=OpenWRT's CPU Benchmark
	URL:=http://wl500g.info/showthread.php?30444
	MAINTAINER:=Entware team, http://entware.net
endef

define Package/cpubench/description
 OpenWRT's CPU Benchmark utility.
endef

define Build/Prepare
	mkdir -p $(PKG_BUILD_DIR)
	$(CP) ./src/openwrt_cpu_bench_v06.c $(PKG_BUILD_DIR)
endef

define Build/Compile
	$(TARGET_CC) -O0 -c -o $(PKG_BUILD_DIR)/cpubench.o $(PKG_BUILD_DIR)/openwrt_cpu_bench_v06.c
	$(TARGET_CC) $(TARGET_LDFLAGS) -o $(PKG_BUILD_DIR)/cpubench $(PKG_BUILD_DIR)/cpubench.o
endef

define Package/cpubench/install
	$(INSTALL_DIR) $(1)/opt/bin
	$(INSTALL_BIN) $(PKG_BUILD_DIR)/cpubench $(1)/opt/bin
endef

$(eval $(call BuildPackage,cpubench))
